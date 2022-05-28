#include <stdio.h> 
#include <string.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int main(){
	
	char all_the_variables[250];
	int the_first_line_has_been_done;
	FILE *p4;
	char coefficients_first[40];
	
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
	
	int m=0;
	
	if(the_first_line_has_been_done == 0){
		
		for(i=0; variables[i] != '\0'; i++){
			
			all_the_variables[m] = variables[i];
			m++;
		}
	}

	the_first_line_has_been_done = 1;
	
	char newline[20];
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

for(m=0; all_the_variables[m] != '\0'; m++){
	
	printf("\ntheseee %c\t", all_the_variables[m]);
}

for(i=0; i<length_of_variables; i++){ 
	
printf("this variable is %c and its coefficient is %f\n",variables_control[i], coefficients_control[i]);
	
}

printf("The constant is %f\n\n", coefficients_control[i]);

}
int length_of_all_the_variables = strlen(all_the_variables);

float matrix[length_of_all_the_variables][length_of_all_the_variables+1];

float result[length_of_all_the_variables];

int nanvalue, infvalue;


for(int b = 0; b < how_many_lines; b++){  // This loop for the equations in the text (line by line).

	for(i=0; lines[b][i] != '\0'; i++){
	
	coefficients_first[i] = lines[b][i];
	printf("%c\n", coefficients_first[i]);
	
	}
		
	j=0;
	

	for(i=0; lines[b][i] != '='; i++){   // This is for the equation's left side.
			
		if (isalpha(lines[b][i]) != 0){  // While checking for every element in the equation if it faces any char, takes it as variable to the vaiables array.
		
            //printf("this is one of the variables %c which is left side of the equation\n", lines[b][i]);
            variables[j] = lines[b][i];
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
	
	int m=0;
	
	if(the_first_line_has_been_done == 0){
		
		for(i=0; variables[i] != '\0'; i++){
			
			all_the_variables[m] = variables[i];
			m++;
		}
	}

	the_first_line_has_been_done = 1;
	
	int length_of_coefficients_first = strlen(coefficients_first);
	
	p4 = fopen("denemetext.txt", "w");
	printf("tttttttt%c\n", coefficients_first[0]);
	
	if(isalpha(coefficients_first[0]) != 0){
		
		fprintf(p4, "%c", '1');
		
			}
	
	for(i=0; i<length_of_coefficients_first; i++){
	
	if (isalpha(coefficients_first[i]) == 0){
		
		fprintf(p4, "%c", coefficients_first[i]);
	}
	
	else if (isalpha(coefficients_first[i]) != 0){
		
		
		if(coefficients_first[i-1] == '-'){
			
			fprintf(p4, "%c%c%c",'1',coefficients_first[i], coefficients_first[i+1]);
			i++;
		}
		
		else if(coefficients_first[i-1] == '+'){
			
			fprintf(p4, "%c%c%c",'1',coefficients_first[i], coefficients_first[i+1]);
			i++;
		}
		
		else{
			
			fprintf(p4, "%c", coefficients_first[i]);
		}
	}   
		

}

fclose(p4);
	
	char newline[40];
	
	p4 = fopen("denemetext.txt", "r");
	
	fscanf(p4,"%s", newline);
	printf("bunewlineeeee%s\n", newline);
	
	//strcpy(newline, lines[b]); // this is to turn lines[0] which is the first equation to a new string to measure its length easily.
	//printf("%s\n", lines[0]);  // both give the same output.
	//printf("%s\n", newline);   // both give the same output.
	int length_of_newline = strlen(newline); // this is to measure lines' length.
	
	fclose(p4);
	
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

matrix[b][length_of_all_the_variables] = coefficients_control[j];

printf("%f\t", matrix[b][length_of_all_the_variables]);

printf("\n");

}


for (int j=0;j<length_of_all_the_variables;j++){ //same as line number
        for(int i=0;i<length_of_all_the_variables;i++){ // coefficients, We do not include the result part in the triangle thats why i dont write coeffnum in here.
            if (i>j){ //This continues until it forms a perpendicular triangle in the matrix with zeros.
                float ratio=matrix[i][j]/matrix[j][j]; //this gets the ratio of a coefficient and next line with same coefficient
                for (int k=0;k<length_of_all_the_variables+1;k++){
                    matrix[i][k] = matrix[i][k]-ratio*matrix[j][k]; //in here we will multiply ratio and upper line and subtract them with current line. One of the coefficients turns 0.
                }
                printf("Next step:\n");
            
                printf("\n");
            }
        }
    }
// Getting results after that perpendicular triangle in matrix is created.
    result[length_of_all_the_variables-1] = matrix[length_of_all_the_variables-1][length_of_all_the_variables]/matrix[length_of_all_the_variables-1][length_of_all_the_variables-1]; // The reason this line is outside the for loop, this performs only 1 time. The reasons for -1's, arrays starts at 0. I mean, for ex. unknum-1 represents last index.
    
    
    for (int i=length_of_all_the_variables-1; i>=0; i--){ // this performs backwards. for ex. from 3rd line to 1st line
        float placenumber=0; // This resets after placenumber is used and gets ready for next step.
        for (int j=i+1;j<=length_of_all_the_variables-1;j++){
            placenumber = placenumber + matrix[i][j] * result[j]; //This multiplies obtained result with unknown in previous line.
        }
        result[i] = (matrix[i][length_of_all_the_variables]-placenumber)/matrix[i][i]; //This obtains the other unknown's result by transferring knowns other side and dividing coefficient.
        
    }
    
    
        printf("RESULTS:\n");//printing results
        for (int i=0;i<length_of_all_the_variables;i++){
            printf("%c is %g\n",all_the_variables[i],result[i]);
        }
    

	return 0;
	
}
