//
//  main.c
//  project3lvl1
//
//  Created by Ali Yiğit Taş on 16.05.2022.
// Sonucu oluşturma eksik

#include <stdio.h>
#include <stdlib.h>

#define MAXUNKNOWNNUMBER 10 //Max variables
#define MAXCOEFFICIENTS MAXUNKNOWNNUMBER+1 //Plus results

double matrix[MAXUNKNOWNNUMBER][MAXCOEFFICIENTS] = {{2,1,-1,1},{3,4,2,13},{1,-5,-2,0}}; //3 değişkenli
double mmatrix[MAXUNKNOWNNUMBER][MAXCOEFFICIENTS]; //üst satırdaki sonuçların yazdırılmaması için var
double nmatrix[MAXUNKNOWNNUMBER][MAXCOEFFICIENTS]; //program başlarken matrix arrayinin yedeğini buraya alıyor daha sonra isteğe bağlı aynı sayılarla yeniden işlem yapılıyor.
double rsltz, rslty, rsltx;
int again;
int unknum = 3; //number of unknowns
int linenum;
int coeffnum;
float ratio;
int j,k;


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
            printf("%fx", matrix[i][0]);
        }
        
        //Print y coefficient
        if (matrix[i][1]==0){
            printf("");
        }else if (matrix[i][1]==1){
            printf("+y");
        }else if (matrix[i][1]==-1){
            printf("-y");
        }else if (matrix[i][0]==0){
            printf("%fy",matrix[i][1]); //if there is no x program does not print + sign before y if its positive.
        }else {
            printf("%+fy", matrix[i][1]);
        }
        
        //Print z coefficient
        if (matrix[i][2]==0){
            printf("");
        }else if (matrix[i][2]==1){
            printf("+z");
        }else if (matrix[i][2]==-1){
            printf("-z");
        }else if (matrix[i][0]==0 && matrix[i][1]==0){
            printf("%fz",matrix[i][2]); //if there is no x program does not print + sign before z if its positive.
        }else {
            printf("%+fz", matrix[i][2]);
        }
        
        //Print result of equation
        if (!(matrix[i][0]==0 && matrix[i][1]==0 && matrix[i][2]==0)){
            printf("=%f\n", matrix[i][3]);
        }
        
    }
}

static void PrintMatrix(){
    
    for (int i=0;i<linenum;i++){ //i<Satır sayısı
        printf("[");
        for (int j=0;j<coeffnum;j++){ //j<Değişken sayısı + sonuç
            if (j==coeffnum-1){//sonuç bu değişkende yazdırılıyor
                printf("%.2f", matrix[i][j]);
            }else{
                printf("%.2f ", matrix[i][j]);
            }
            if (j==coeffnum-2){ //Sonuçtan önceki ayırma işareti, j==(Değişken sayısı + sonuç)-2
                printf(": ");
            }
        }
        printf("]\n");
    }
}

static void Solve(){
    printf("Matrix Form:\n");
    PrintMatrix();
    printf("\n");
    //Solving
    for (int j=0;j<unknum;j++){
        for(int i=0;i<unknum;i++){
            if (i>j){ //Creates triangle in matrix
                ratio=matrix[i][j]/matrix[j][j];
                for (int k=0;k<coeffnum;k++){
                    matrix[i][k] = matrix[i][k]-ratio*matrix[j][k];
                }
                printf("Next step:\n");
                PrintMatrix();
                printf("\n");
            }
        }
    }

    rsltz = matrix[2][3] / matrix[2][2]; //bu kısım değişecek
    rslty = (matrix[1][3] - (matrix[1][2]*rsltz)) / matrix[1][1];
    rsltx = (matrix[0][3] - (matrix[0][2]*rsltz) - (matrix[0][1]*rslty)) / matrix[0][0];
    
    if (matrix[linenum-1][0] ==0 && matrix[linenum-1][1] ==0 && matrix[linenum-1][2] ==0 && matrix[linenum-1][3]==0){ //ifin içinde for kullan coeff için
        printf("This equation has multiple solutions! This is one of them:\n");
        printf("x is %.2f\n",rsltx);
        printf("y is %.2f\n",rslty);
        printf("z is %.2f\n",rsltz);
    }else if (matrix[linenum-1][0] ==0 && matrix[linenum-1][1] ==0 && matrix[linenum-1][2] ==0 && matrix[linenum-1][3]!=0){ //arrays starts at 0, linenum-1 means last line
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
    for (int i=0;i<MAXUNKNOWNNUMBER;i++){
        for (int j=0;j<MAXCOEFFICIENTS;j++){
            nmatrix[i][j] = matrix[i][j];
        }
    }
    PrintEquations();
    printf("\n");
    Solve();
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
            for (int i=0;i<MAXUNKNOWNNUMBER;i++){
                for (int j=0;j<MAXCOEFFICIENTS;j++){
                    matrix[i][j] = nmatrix[i][j];
                }
            }
            main();
        case 2:
            break;
        default:
            printf("Please select Yes or No.\n");
            AfterSolving();
    }
}

