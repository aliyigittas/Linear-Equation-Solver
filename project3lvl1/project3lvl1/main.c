//
//  main.c
//  project3lvl1
//
//  Created by Ali Yiğit Taş on 16.05.2022.
// matrix[satır numarası-1][x=0,y=1,z=2,result=3]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int matrix[10][4] = {{1,-5,3,-8},{0,2,1,3},{0,0,0,7}};
int mx[3];
int my[3];
int mz[3];
int mresults[3];
int nx[3];
int ny[3];
int nz[3];
int nresults[3];
double rsltz;
double rslty;
double rsltx;
int again;

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

static void FirstStep3unk(){
    printf("First Step:\n");
    for (int i=0;i<3;i++){
        printf("[%d %d %d : %d]\n", matrix[i][0],matrix[i][1],matrix[i][2],matrix[i][3]);
    }
}

static void Solve3unk(){
    printf("Second Step:\n");
    
    mx[0] = matrix[0][0] * matrix[1][0];                   //İlk satır
    my[0] = matrix[0][1] * matrix[1][0];                   //ikinci satırdaki
    mz[0] = matrix[0][2] * matrix[1][0];                   //x katsayısı ile çarpıldı.
    mresults[0] = matrix[0][3] * matrix[1][0];       //Yazdırılmaması için farklı değişkene atandı.
    
    
    matrix[1][0] = (matrix[1][0] * matrix[0][0]) - mx[0];                          //İkinci satır ilk satırdaki
    matrix[1][1] = (matrix[1][1] * matrix[0][0]) - my[0];                          //x katsayısı ile çarpıldı.
    matrix[1][2] = (matrix[1][2] * matrix[0][0]) - mz[0];                          //ilk satırdan çıkarıldı.
    matrix[1][3] = (matrix[1][3] * matrix[0][0]) - mresults[0];                    // Yazdırılacak.

    
    
    mx[0] = matrix[0][0] * matrix[2][0];                   //1. satır
    my[0] = matrix[0][1] * matrix[2][0];                   //3. satırdaki
    mz[0] = matrix[0][2] * matrix[2][0];                   //x katsayısı ile çarpıldı.
    mresults[0] = matrix[0][3] * matrix[2][0];             //Yazdırılmaması için farklı değişkene atandı.
    
    
    
    matrix[2][0] = (matrix[2][0] * matrix[0][0]) - mx[0];                          //3. satır ilk satırdaki
    matrix[2][1] = (matrix[2][1] * matrix[0][0]) - my[0];                          //x katsayısı ile çarpıldı.
    matrix[2][2] = (matrix[2][2] * matrix[0][0]) - mz[0];                          //1. satırdan çıkarıldı.
    matrix[2][3] = (matrix[2][3] * matrix[0][0]) - mresults[0];                    // Yazdırılacak.
    
    
    for (int i=0;i<3;i++){
        printf("[%d %d %d : %d]\n", matrix[i][0],matrix[i][1],matrix[i][2],matrix[i][3]);
    }
    printf("\n");
    
    printf("Third Step:\n");
    
    //There is no need to multiply x with y[2] because its already zero in both lines.
    
    my[1] = matrix[1][1] * matrix[2][1];                    //2. satır 3. satırdaki
    mz[1] = matrix[1][2] * matrix[2][1];                    //y katsayısı ile çarpıldı.
    mresults[1] = matrix[1][3] * matrix[2][1];        //Yazdırılmaması için farklı değişkene atandı.
    
    
    matrix[2][1] = (matrix[2][1] * matrix[1][1]) - my[1];                     //3. satır ve 2. satır y değeri çarpıldı
    matrix[2][2] = (matrix[2][2] * matrix[1][1]) - mz[1];                     //3. satırdan
    matrix[2][3] = (matrix[2][3] * matrix[1][1]) - mresults[1];               //2. satır çıkarıldı.
    
    
    for (int i=0;i<3;i++){
        printf("[%d %d %d : %d]\n", matrix[i][0],matrix[i][1],matrix[i][2],matrix[i][3]);
    }
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
        printf("x is %f\n",rsltx);
        printf("y is %f\n",rslty);
        printf("z is %f\n",rsltz);
    }
}


int main() {
    
    for (int i=0;i<3;i++){
        nx[i] = matrix[i][0];
        ny[i] = matrix[i][1];
        nz[i] = matrix[i][2];
        nresults[i] = matrix[i][3];
    }
    PrintEquations();
    printf("\n");
    FirstStep3unk();
    printf("\n");
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
                matrix[i][0] = nx[i];
                matrix[i][1] = ny[i];
                matrix[i][2] = nz[i];
                matrix[i][3] = nresults[i];
            }
            main();
        case 2:
            break;
        default:
            printf("Please select Yes or No.\n");
            AfterSolving();
    }
}

