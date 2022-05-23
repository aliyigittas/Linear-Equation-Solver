//
//  main.c
//  project3lvl1
//
//  Created by Ali Yiğit Taş on 16.05.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXUNKNOWNNUMBER 10 //Max variables
#define MAXCOEFFICIENTS MAXUNKNOWNNUMBER+1 //Plus results
#define unknownumber 3 //current unknown number

double matrix[MAXUNKNOWNNUMBER][MAXCOEFFICIENTS] = {{2,1,-1,1},{3,4,2,13},{1,-5,-2,0}}; //3 değişkenli
double nmatrix[MAXUNKNOWNNUMBER][MAXCOEFFICIENTS]; // at the beginning program takes a copy of matrix array in here for if user wants to solve again.
double result[unknownumber]; //results are stored in here
char unknames[MAXUNKNOWNNUMBER] = {'x','y','z','a','b','c','d','e','f','g'}; //these are unknown names
int again; //this is used for switch
int unknum = unknownumber; //number of unknowns
int linenum; //same as unknum
int coeffnum; //coeffnum = unknum + 1 (result)
int nanvalue, infvalue; // stores number of NaN and inf values.
float ratio; // this variable stores ratios while solving
float placenumber; // this is used in back-substitution part


static void AfterSolving(void);

static void PrintEquations() { //prints equations
    
    printf("Equations:\n");
    
    for (int i=0;i<unknum;i++){ //printing lines
        for (int j=0; j<unknum; j++){ //printing coefficients
            if (matrix[i][j]==0){ //if there is no coeff. unk. name does not print.
                printf("");
            }else if (matrix[i][j]==1 && j==0){ //if the coeff. is 1 and first element in equation this does not print extra + sign.
                printf("%c",unknames[j]);
            }else if (matrix[i][j]==1){ //if the coeff is 1 this will only print unknown name.
                printf("+%c",unknames[j]);
            }else if (matrix[i][j]==-1){ //if the coeff is -1 this will only print - sign and only unknown name.
                printf("-%c",unknames[j]);
            }else {
                if (j==0){
                    printf("%g%c", matrix[i][j],unknames[j]); //if first coeff is first element in the equation this does not print extra + sign.
                }else {
                    printf("%+g%c", matrix[i][j],unknames[j]); //if first coeff is first element in the equation this prints - sign if its negative.
                }
                
            }
            
        }
        printf("=%g\n",matrix[i][coeffnum-1]); //prints results.

    }
}

static void PrintMatrix(){
    
    for (int i=0;i<linenum;i++){ //i<line number
        printf("[");
        for (int j=0;j<coeffnum;j++){ //j<unknown number plus result
            if (j==coeffnum-1){//print result in matrix (last element)
                printf("%.2f", matrix[i][j]);
            }else{//if its not last element this adds blank space.
                printf("%.2f ", matrix[i][j]);
            }
            if (j==coeffnum-2){ // Before pirnting result, this adds : sign for better understanding.
                printf(": ");
            }
        }
        printf("]\n");
    }
}

static void Solve(){
    printf("Matrix Form:\n");
    PrintMatrix(); //Prints matrix form with given equations.
    printf("\n");
    //Solving part
    for (int j=0;j<unknum;j++){ //same as line number
        for(int i=0;i<unknum;i++){ // coefficients, We do not include the result part in the triangle thats why i dont write coeffnum in here.
            if (i>j){ //This continues until it forms a perpendicular triangle in the matrix with zeros.
                ratio=matrix[i][j]/matrix[j][j]; //this gets the ratio of a coefficient and next line with same coefficient
                for (int k=0;k<coeffnum;k++){
                    matrix[i][k] = matrix[i][k]-ratio*matrix[j][k]; //in here we will multiply ratio and upper line and subtract them with current line. One of the coefficients turns 0.
                }
                printf("Next step:\n");
                PrintMatrix(); //prints matrix after this step.
                printf("\n");
            }
        }
    }
// Getting results after that perpendicular triangle in matrix is created.
    result[unknum-1] = matrix[unknum-1][coeffnum-1]/matrix[unknum-1][unknum-1]; // The reason this line is outside the for loop, this performs only 1 time. The reasons for -1's, arrays starts at 0. I mean, for ex. unknum-1 represents last index.
    
    
    for (int i=linenum-1; i>=0; i--){ // this performs backwards. for ex. from 3rd line to 1st line
        placenumber=0; // This resets after placenumber is used and gets ready for next step.
        for (int j=i+1;j<=linenum-1;j++){
            placenumber = placenumber + matrix[i][j] * result[j]; //This multiplies obtained result with unknown in previous line.
        }
        result[i] = (matrix[i][coeffnum-1]-placenumber)/matrix[i][i]; //This obtains the other unknown's result by transferring knowns other side and dividing coefficient.
        
    }
    
    
    
}

static void PrintResults(){
    
    //Bonus part with printing results
    for (int i=0; i<coeffnum+1; i++){ //+1 for checking result
        if (isnan(result[i])){ //checking if its NaN or not
            nanvalue++;
        }
        if (isinf(result[i])){ //checking if its inf (infinite) value or not
            infvalue++;
        }
    }
    
    if (nanvalue == unknum){                               //if all results have NaN value (0/0)
        printf("This equation has multiple solutions!\n"); //print this
    }else if (infvalue == unknum){                   //if all results have infinite value (for ex. 7/0)
        printf("This equation has no solutions!\n"); //print this.
    }else{
        printf("RESULTS:\n");//printing results
        for (int i=0;i<unknum;i++){
            printf("%c is %g\n",unknames[i],result[i]);
        }
    }
}


int main() {
    linenum = unknum; // line number is number of equations
    coeffnum = unknum + 1;//+1 is results
    for (int i=0;i<MAXUNKNOWNNUMBER;i++){ //copies matrix to another array for if user wants to solving again.
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

static void AfterSolving(){ //This includes recursive function Bonus
    printf("Do you want to solve again?\n");
    printf("1.Yes\n");
    printf("2.No\n");
    printf("Your Selection:");
    scanf("%d",&again);
    switch (again) {
        case 1:
            for (int i=0;i<MAXUNKNOWNNUMBER;i++){
                for (int j=0;j<MAXCOEFFICIENTS;j++){
                    matrix[i][j] = nmatrix[i][j]; //This transfers backup to original array.
                }
            }
            main(); //starts the program from beginning
        case 2:
            break;
        default: //if user selects other than 1 or 2 this function runs again.
            printf("Please select Yes or No.\n");
            AfterSolving();
    }
}

