//
//  main.c
//  project3lvl1
//
//  Created by Ali Yiğit Taş on 16.05.2022.
// Sadece eşitsizlikleri yazma kısmında sorun var olmazsa da pek önemli değil

#include <stdio.h>
#include <stdlib.h>

#define MAXUNKNOWNNUMBER 10 //Max variables
#define MAXCOEFFICIENTS MAXUNKNOWNNUMBER+1 //Plus results
#define unknownumber 2

double matrix[MAXUNKNOWNNUMBER][MAXCOEFFICIENTS] = {{4,-2,20},{-5,-5,-10}}; //2 değişkenli
double nmatrix[MAXUNKNOWNNUMBER][MAXCOEFFICIENTS]; //program başlarken matrix arrayinin yedeğini buraya alıyor daha sonra isteğe bağlı aynı sayılarla yeniden işlem yapılıyor.
//double rsltz, rslty, rsltx;
double result[unknownumber];
char unknames[MAXUNKNOWNNUMBER] = {'x','y','z'};
int again;
int unknum = unknownumber; //number of unknowns
int linenum;
int coeffnum;
float ratio;
float placenumber;


static void AfterSolving(void);

static void PrintEquations() { /* This is not unknown number-spesific*/
    
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
            printf("%.0fx", matrix[i][0]);
        }
        
        //Print y coefficient
        if (matrix[i][1]==0){
            printf("");
        }else if (matrix[i][1]==1){
            printf("+y");
        }else if (matrix[i][1]==-1){
            printf("-y");
        }else if (matrix[i][0]==0){
            printf("%.0fy",matrix[i][1]); //if there is no x program does not print + sign before y if its positive.
        }else {
            printf("%+.0fy", matrix[i][1]);
        }
        
        //Print z coefficient
        if (matrix[i][2]==0){
            printf("");
        }else if (matrix[i][2]==1){
            printf("+z");
        }else if (matrix[i][2]==-1){
            printf("-z");
        }else if (matrix[i][0]==0 && matrix[i][1]==0){
            printf("%.0fz",matrix[i][2]); //if there is no x program does not print + sign before z if its positive.
        }else {
            printf("%.0fz", matrix[i][2]);
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
// sonuçlar burada result arraye taşınıyor
    result[unknum-1] = matrix[unknum-1][coeffnum-1]/matrix[unknum-1][unknum-1]; //for dışında olma sebebi bu sadece bir kere yapılıyor array 0 den başladığı için -1 var yani 3 değişken varsa unknum-1=2 yani arrayin 3. elemanını temsil ediyor.
    
    for (int i=linenum-1; i>=0; i--){
        placenumber=0;
        for (int j=i+1;j<=linenum-1;j++){
            placenumber = placenumber + matrix[i][j] * result[j];
        }
        result[i] = (matrix[i][coeffnum-1]-placenumber)/matrix[i][i];
        
    }
    
    
    
}

static void PrintResults(){
    
    if (matrix[linenum-1][0] ==0 && matrix[linenum-1][1] ==0 && matrix[linenum-1][2] ==0 && matrix[linenum-1][3]==0){ //ifin içinde for kullan coeff için
        printf("This equation has multiple solutions!\n");
    }else if (matrix[linenum-1][0] ==0 && matrix[linenum-1][1] ==0 && matrix[linenum-1][2] ==0 && matrix[linenum-1][3]!=0){ //arrays starts at 0, linenum-1 means last line
        printf("This equation has no solutions!\n");
    }else{
        printf("RESULTS:\n");
        for (int i=0;i<unknum;i++){
            printf("%c is %.2f\n",unknames[i],result[i]);
        }
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
    PrintResults();
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

