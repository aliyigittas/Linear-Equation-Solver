//
//  main.c
//  project3lvl1
//
//  Created by Ali Yiğit Taş on 16.05.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAXUNKNOWNNUMBER 10 //Max variables
#define MAXCOEFFICIENTS MAXUNKNOWNNUMBER+1 //Plus results
//#define unknownumber 3 //current unknown number

double matrix[MAXUNKNOWNNUMBER][MAXCOEFFICIENTS] ; //{{2,1,-1,1},{3,4,2,13},{1,-5,-2,0}}; //3 değişkenli
double nmatrix[MAXUNKNOWNNUMBER][MAXCOEFFICIENTS]; // at the beginning program takes a copy of matrix array in here for if user wants to solve again.
double result[MAXUNKNOWNNUMBER]; //results are stored in here
char unknames[MAXUNKNOWNNUMBER]; //= {'x','y','z','a','b','c','d','e','f','g'}; //these are unknown names
int again; //this is used for switch
int unknum ;//= unknownumber; //number of unknowns
int linenum; //same as unknum
int coeffnum; //coeffnum = unknum + 1 (result)
int nanvalue, infvalue; // stores number of NaN and inf values.
float ratio; // this variable stores ratios while solving
float placenumber; // this is used in back-substitution part


static void AfterSolving(void);

static void ReadFromFile () {
	char all_the_variables[250];
	int the_first_line_has_been_done;

    char lines[250][250];  //This 2d array keeps the lines in the text.
	FILE *p;
	p = fopen("text.txt", "r");
	int i = 0;

	 while(!feof(p)){             //Reading equations line by line from the text.
	fscanf(p,"%s",lines[i]);
	printf("%s\n", lines[i]);
	i++;
	}

	fclose(p);

	int how_many_lines = i;

	char variables[10];    //This is to keep variables here.

	lines[i][250] = '\0';

	int j = 0; //for variables

	for(int b = 0; b < how_many_lines; b++){  // This loop for the equations in the text (line by line).

	j=0;


	for(i=0; lines[b][i] != '='; i++){   // This is for the equation's left side.

		if (isalpha(lines[b][i]) != 0){  // While checking for every element in the equation if it faces any char, takes it as variable to the vaiables array.

            //printf("this is one of the variables %c which is left side of the equation\n", lines[b][i]);
            variables[j] = lines[b][i];
            //unknames[j] = variables[j];
            //printf("this is the %d. variable = %c which is left side of the equation\n", j, variables[j]);
            j++;

			}
        }


		//printf("%c\n", firstline[i]);


	for(; lines[b][i] != '\0'; i++){  // This is for the equation's right side.

		if (isalpha(lines[b][i]) != 0){  // While checking for every element in the equation if it faces any char, takes it as variable to the vaiables array.

            //printf("this is one of the variables %c which is right side of the equation\n", lines[b][i]);
            variables[j] = lines[b][i];
            //printf("this is the %d. variable = %c which is right side of the equation\n", j, variables[j]);
            j++;
        }

	}

	variables[j] = '\0';  // This is to limit variables array to measure its length later.

	float coefficients_control[20];  // coefficients will be in this array.
	char variables_control[20];      // variables with respect to its coefficients will be in this array.
	char a[20];

	int length_of_variables = strlen(variables); //the length for variables array.
	unknum = length_of_variables;
	linenum = unknum;
	coeffnum = unknum + 1;

	int m=0;

	if(the_first_line_has_been_done == 0){

		for(i=0; variables[i] != '\0'; i++){

			all_the_variables[m] = variables[i];
			unknames[i] = variables[i];
			m++;
		}
	}

	the_first_line_has_been_done = 1;


	char newline[200];
	strcpy(newline, lines[b]); // this is to turn lines[0] which is the first equation to a new string to measure its length easily.
	//printf("%s\n", lines[0]);  // both give the same output.
	//printf("%s\n", newline);   // both give the same output.
	int length_of_newline = strlen(newline); // this is to measure lines' length.

	p = fopen("lines.txt", "w");            // Here we put " " instead of "=" in the equation to easily get the coefficients and variables with %f%c method.
	for(i=0; i < length_of_newline; i++){

		if(newline[i] == '='){

			newline[i] = ' ';

		}
	}

	fprintf(p, "%s", newline);   // and writing it to a new file.

	fclose(p);

	p = fopen("lines.txt", "r");


	for(i=0; i<length_of_variables + 1; i++){    // reading the new equation from the new file and get %f for coefficients and get %c for their variables.

fscanf(p,"%f%c", &coefficients_control[i], &variables_control[i]);
//printf("%f%c\n",coefficients_control[i], variables_control[i]);
matrix[b][i] = coefficients_control[i];

	}

fclose(p);

int length_of_all_the_variables = strlen(all_the_variables);
int the_decider;

for(i=0; i<length_of_variables; i++){

the_decider = 0;

	for(m=0; m<length_of_all_the_variables; m++){

		if(variables[i] == all_the_variables[m]){

			the_decider=1;
		}
	}

	if(the_decider == 0){

		all_the_variables[m] = variables[i];

	//	printf("\n%c hehe\n", all_the_variables[m]);
	}

}

for(int b = 0; b < how_many_lines; b++){  // This loop for the equations in the text (line by line).

	j=0;


	for(i=0; lines[b][i] != '='; i++){   // This is for the equation's left side.

		if (isalpha(lines[b][i]) != 0){  // While checking for every element in the equation if it faces any char, takes it as variable to the vaiables array.

            //printf("this is one of the variables %c which is left side of the equation\n", lines[b][i]);
            variables[j] = lines[b][i];
            //unknames[j] = variables[j];
            //printf("this is the %d. variable = %c which is left side of the equation\n", j, variables[j]);
            j++;

			}
        }


		//printf("%c\n", firstline[i]);


	for(; lines[b][i] != '\0'; i++){  // This is for the equation's right side.

		if (isalpha(lines[b][i]) != 0){  // While checking for every element in the equation if it faces any char, takes it as variable to the vaiables array.

            //printf("this is one of the variables %c which is right side of the equation\n", lines[b][i]);
            variables[j] = lines[b][i];
            //printf("this is the %d. variable = %c which is right side of the equation\n", j, variables[j]);
            j++;
        }

	}

	variables[j] = '\0';  // This is to limit variables array to measure its length later.

	float coefficients_control[20];  // coefficients will be in this array.
	char variables_control[20];      // variables with respect to its coefficients will be in this array.
	char a[20];

	int length_of_variables = strlen(variables); //the length for variables array.
	unknum = length_of_variables;
	linenum = unknum;
	coeffnum = unknum + 1;

	int m=0;

	if(the_first_line_has_been_done == 0){

		for(i=0; variables[i] != '\0'; i++){

			all_the_variables[m] = variables[i];

			m++;
		}
	}

	the_first_line_has_been_done = 1;

	char newline[200];
	strcpy(newline, lines[b]); // this is to turn lines[0] which is the first equation to a new string to measure its length easily.
	//printf("%s\n", lines[0]);  // both give the same output.
	//printf("%s\n", newline);   // both give the same output.
	int length_of_newline = strlen(newline); // this is to measure lines' length.

	p = fopen("lines.txt", "w");            // Here we put " " instead of "=" in the equation to easily get the coefficients and variables with %f%c method.
	for(i=0; i < length_of_newline; i++){

		if(newline[i] == '='){

			newline[i] = ' ';

		}
	}

	fprintf(p, "%s", newline);   // and writing it to a new file.

	fclose(p);

	p = fopen("lines.txt", "r");


	for(i=0; i<length_of_variables + 1; i++){    // reading the new equation from the new file and get %f for coefficients and get %c for their variables.

fscanf(p,"%f%c", &coefficients_control[i], &variables_control[i]);
//printf("%f%c\n",coefficients_control[i], variables_control[i]);
	}

fclose(p);

//for(i=0; i<length_of_variables; i++){
//printf("%c \n", variables[i]);
//}

//for(m=0; all_the_variables[m] != '\0'; m++){

//	printf("\ntheseee %c\t", all_the_variables[m]);
//}

int length_of_all_the_variables = strlen(all_the_variables);


int the_count;
int the_another_count=0;

//float matrix[length_of_all_the_variables][length_of_all_the_variables+1];


for(i=0; i<length_of_all_the_variables; i++){

	the_count=0;

	for(j=0; j<length_of_variables; j++){

		if(all_the_variables[i] == variables_control[j]){

			matrix[b][i] = coefficients_control[j];
			printf("%f\t", matrix[b][i]);
			the_count=1;
			the_another_count++;
		}
	}

	if(the_count != 1){

		matrix[b][i] = 0.0;
		printf("%f\t", matrix[b][i]);
	}
}

matrix[b][coeffnum] = coefficients_control[j];

printf("%f\t", matrix[b][length_of_all_the_variables]);
matrix[b][unknum] = coefficients_control[i];

printf("\n");
}
}

//printf("The constant is %f\n", coefficients_control[i]);

}





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
    //linenum = unknum; // line number is number of equations
    //coeffnum = unknum + 1;//+1 is results
    for (int i=0;i<MAXUNKNOWNNUMBER;i++){ //copies matrix to another array for if user wants to solving again.
        for (int j=0;j<MAXCOEFFICIENTS;j++){
            nmatrix[i][j] = matrix[i][j];
        }
    }
    ReadFromFile();
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

