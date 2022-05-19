//
//  main.c
//  project3lvl1
//
//  Created by Ali Yiğit Taş on 16.05.2022.
// matrix[satır sayısı-1][x=0,y=1,z=2,result=3]

#include <stdio.h>
#include <stdlib.h>

#define MAXUNKNOWNNUMBER 100 //Max variables
#define MAXCOEFFICIENTS MAXUNKNOWNNUMBER+1 //Plus results

int matrix[MAXUNKNOWNNUMBER][MAXCOEFFICIENTS] = {{2,1,-1,1},{3,4,2,13},{1,-5,-2,0}};
int mmatrix[MAXUNKNOWNNUMBER][MAXCOEFFICIENTS]; //üst satırdaki sonuçların yazdırılmaması için var
int nmatrix[MAXUNKNOWNNUMBER][MAXCOEFFICIENTS]; //program başlarken matrix arrayinin yedeğini buraya alıyor daha sonra isteğe bağlı aynı sayılarla yeniden işlem yapılıyor.
double rsltz, rslty, rsltx;
int again;
int unknum = 3; //number of unknowns
int linenum;
int coeffnum;

static void AfterSolving(void);

static void PrintEquations() {
    
    printf("Equations:\n");
    
    for (int i=0;i<3;i++){
        
        //Print x coefficient
        if (matrix[i][0]==0){
            printf("");
        }else if (matrix[i][0]==1){
            printf("x");
        }else if (matrix[i][0]==-1){
            printf("-x");
        }else {
            printf("%dx", matrix[i][0]);
        }
        
        //Print y coefficient
        if (matrix[i][1]==0){
            printf("");
        }else if (matrix[i][1]==1){
            printf("+y");
        }else if (matrix[i][1]==-1){
            printf("-y");
        }else if (matrix[i][0]==0){
            printf("%dy",matrix[i][1]); //if there is no x program does not print + sign before y if its positive.
        }else {
            printf("%+dy", matrix[i][1]);
        }
        
        //Print z coefficient
        if (matrix[i][2]==0){
            printf("");
        }else if (matrix[i][2]==1){
            printf("+z");
        }else if (matrix[i][2]==-1){
            printf("-z");
        }else if (matrix[i][0]==0 && matrix[i][1]==0){
            printf("%dz",matrix[i][2]); //if there is no x program does not print + sign before z if its positive.
        }else {
            printf("%+dz", matrix[i][2]);
        }
        
        //Print result of equation
        if (!(matrix[i][0]==0 && matrix[i][1]==0 && matrix[i][2]==0)){
            printf("=%d\n", matrix[i][3]);
        }
        
    }
}

static void PrintMatrix(){
    
    for (int i=0;i<linenum;i++){ //i<Satır sayısı
        printf("[");
        for (int j=0;j<coeffnum;j++){ //j<Değişken sayısı + sonuç
            if (j==coeffnum-1){//sonuç bu değişkende yazdırılıyor
                printf("%d", matrix[i][j]);
            }else{
                printf("%d ", matrix[i][j]);
            }
            if (j==coeffnum-2){ //Sonuçtan önceki ayırma işareti, j==(Değişken sayısı + sonuç)-2
                printf(": ");
            }
        }
        printf("]\n");
    }
}

static void Solve3unk(){
    printf("First Step:\n");
    
    PrintMatrix();
    printf("\n");
    
    printf("Second Step:\n");
    
    mmatrix[0][0] = matrix[0][0] * matrix[1][0];                   //İlk satır
    mmatrix[0][1] = matrix[0][1] * matrix[1][0];                   //ikinci satırdaki
    mmatrix[0][2] = matrix[0][2] * matrix[1][0];                   //x katsayısı ile çarpıldı.
    mmatrix[0][3] = matrix[0][3] * matrix[1][0];                   //Yazdırılmaması için farklı değişkene atandı.
    
    
    matrix[1][0] = (matrix[1][0] * matrix[0][0]) - mmatrix[0][0];                          //İkinci satır ilk satırdaki
    matrix[1][1] = (matrix[1][1] * matrix[0][0]) - mmatrix[0][1];                          //x katsayısı ile çarpıldı.
    matrix[1][2] = (matrix[1][2] * matrix[0][0]) - mmatrix[0][2];                          //ilk satırdan çıkarıldı.
    matrix[1][3] = (matrix[1][3] * matrix[0][0]) - mmatrix[0][3];                          // Yazdırılacak.

    
    
    mmatrix[0][0] = matrix[0][0] * matrix[2][0];                   //1. satır
    mmatrix[0][1] = matrix[0][1] * matrix[2][0];                   //3. satırdaki
    mmatrix[0][2] = matrix[0][2] * matrix[2][0];                   //x katsayısı ile çarpıldı.
    mmatrix[0][3] = matrix[0][3] * matrix[2][0];                   //Yazdırılmaması için farklı değişkene atandı.
    
    
    
    matrix[2][0] = (matrix[2][0] * matrix[0][0]) - mmatrix[0][0];                          //3. satır ilk satırdaki
    matrix[2][1] = (matrix[2][1] * matrix[0][0]) - mmatrix[0][1];                          //x katsayısı ile çarpıldı.
    matrix[2][2] = (matrix[2][2] * matrix[0][0]) - mmatrix[0][2];                          //1. satırdan çıkarıldı.
    matrix[2][3] = (matrix[2][3] * matrix[0][0]) - mmatrix[0][3];                          // Yazdırılacak.
    
    
    PrintMatrix();
    /*for (int i=0;i<3;i++){
        printf("[%d %d %d : %d]\n", matrix[i][0],matrix[i][1],matrix[i][2],matrix[i][3]);
    }*/
    printf("\n");
    
    printf("Third Step:\n");
    
    //There is no need to multiply x with y[2] because its already zero in both lines.
    
    mmatrix[1][1] = matrix[1][1] * matrix[2][1];                    //2. satır 3. satırdaki
    mmatrix[1][2] = matrix[1][2] * matrix[2][1];                    //y katsayısı ile çarpıldı.
    mmatrix[1][3] = matrix[1][3] * matrix[2][1];                    //Yazdırılmaması için farklı değişkene atandı.
    
    
    matrix[2][1] = (matrix[2][1] * matrix[1][1]) - mmatrix[1][1];                     //3. satır ve 2. satır y değeri çarpıldı
    matrix[2][2] = (matrix[2][2] * matrix[1][1]) - mmatrix[1][2];                     //3. satırdan
    matrix[2][3] = (matrix[2][3] * matrix[1][1]) - mmatrix[1][3];                     //2. satır çıkarıldı.
    
    
    PrintMatrix();
    /*for (int i=0;i<3;i++){
        printf("[%d %d %d : %d]\n", matrix[i][0],matrix[i][1],matrix[i][2],matrix[i][3]);
    }*/
    printf("\n");
    
    rsltz = matrix[2][3] / matrix[2][2];
    rslty = (matrix[1][3] - (matrix[1][2]*rsltz)) / matrix[1][1];
    rsltx = (matrix[0][3] - (matrix[0][2]*rsltz) - (matrix[0][1]*rslty)) / matrix[0][0];
    
    if (matrix[2][0] ==0 && matrix[2][1] ==0 && matrix[2][2] ==0 && matrix[2][3]==0){
        printf("This equation has multiple solutions! This is one of them:\n");
        printf("x is %f\n",rsltx);
        printf("y is %f\n",rslty);
        printf("z is %f\n",rsltz);
    }else if (matrix[2][0] ==0 && matrix[2][1] ==0 && matrix[2][2] ==0 && matrix[2][3]!=0){
        printf("This equation has no solutions!\n");
    }else{
        printf("RESULTS:\n");
        printf("x is %.2f\n",rsltx);
        printf("y is %.2f\n",rslty);
        printf("z is %.2f\n",rsltz);
    }
}


int main() {
    linenum = unknum;
    coeffnum = unknum + 1;//+1 is results
    for (int i=0;i<3;i++){
        nmatrix[i][0] = matrix[i][0];
        nmatrix[i][1] = matrix[i][1];
        nmatrix[i][2] = matrix[i][2];
        nmatrix[i][3] = matrix[i][3];
    }
    PrintEquations();
    printf("\n");
    //PrintMatrix();
    //printf("\n");
    Solve3unk();
    printf("\n");
    AfterSolving();
    
    return 0;
}

static void AfterSolving(){
    printf("Do you want to solve again?\n");
    printf("1.Yes\n");
    printf("2.No\n");
    printf("Your Selection:");
    scanf("%d",&again);
    switch (again) {
        case 1:
            for (int i=0;i<3;i++){
                matrix[i][0] = nmatrix[i][0];
                matrix[i][1] = nmatrix[i][1];
                matrix[i][2] = nmatrix[i][2];
                matrix[i][3] = nmatrix[i][3];
            }
            main();
        case 2:
            break;
        default:
            printf("Please select Yes or No.\n");
            AfterSolving();
    }
}

