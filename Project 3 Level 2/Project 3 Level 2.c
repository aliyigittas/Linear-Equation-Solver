#include <stdio.h> 
#include <string.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

static void AfterSolving(void); //This is for recursive function to close program.

int main(){
	
	int nanvalue, infvalue; //These are for checking multiple solutions and no solutions.
	char all_the_variables[250]; //This is for keeping all the variables in the text.
	int the_first_line_has_been_done; //
	FILE *trial; // This is for putting "1" to the variables which don't have any constant near.
	char coefficients_first[40]; //This is for keeping the version of the lines added "1".
	float the_constant_left; // This is for the constans which are left side of the equation.
	
	char lines[250][250];  //This 2d array keeps the lines in the text.
	FILE *p; // This is for the equation.
	p = fopen("text.txt", "r");
	int i = 0;
	
	 while(!feof(p)){             //Reading equations line by line from the text.
	fscanf(p,"%s",lines[i]); 
	printf("%s\n", lines[i]);
	i++;
	}

	fclose(p);
	
	int how_many_lines = i;  // This is for keeping the number of equations.
	
	char variables[10];    //This is to keep one line's variables.
	
	lines[i][250] = '\0';  //This is for cleaning the lines.
	
	int j = 0; //for one line's variables to keep in variables[j].
	
	for(int b = 0; b < how_many_lines; b++){  // This loop for the equations in the text (line by line).
		
	j=0;
	

	for(i=0; lines[b][i] != '='; i++){   // This is for the equation's left side.
			
		if (isalpha(lines[b][i]) != 0){  // While checking for every element in the equation if it faces any char, takes it as variable to the vaiables array.
		 
            variables[j] = lines[b][i];
            j++;
            	
			}
        }
        
	
	
	for(; lines[b][i] != '\0'; i++){  // This is for the equation's right side.
		
		if (isalpha(lines[b][i]) != 0){  // While checking for every element in the equation if it faces any char, takes it as variable to the vaiables array.
		
            variables[j] = lines[b][i];
            j++;
        }
		
	}
	
	
	variables[j] = '\0';  // This is to limit variables array to measure its length later.
	
	float coefficients_control[20];  // coefficients will be in this array.
	char variables_control[20];      // variables with respect to its coefficients will be in this array.
	char a[20];
	
	int length_of_variables = strlen(variables); //the length for variables array.
	
	int m=0;  // This is for keeping all_the_variables[m].
	
	if(the_first_line_has_been_done == 0){  //If all the variables are not found in the first line, it adds the variables from the other line to the set.
 
		
		for(i=0; variables[i] != '\0'; i++){
			
			all_the_variables[m] = variables[i];
			m++;
		}
	}

	the_first_line_has_been_done = 1; 
	
	char newline[200];   
	strcpy(newline, lines[b]); // this is to turn lines[0] which is the first equation to a new string to measure its length easily.

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

	}
	
fclose(p);

int length_of_all_the_variables = strlen(all_the_variables);
int the_decider; //This is for adding new variables.

for(i=0; i<length_of_variables; i++){
	
	the_decider = 0;
	
	for(m=0; m<length_of_all_the_variables; m++){
		
		if(variables[i] == all_the_variables[m]){
			
			the_decider=1;
		}
	}
	
	if(the_decider == 0){
		
		all_the_variables[m] = variables[i];
	}
}


}
int length_of_all_the_variables = strlen(all_the_variables);

float matrix[length_of_all_the_variables][length_of_all_the_variables+1];

float result[length_of_all_the_variables];




for(int b = 0; b < how_many_lines; b++){  // This loop for the equations in the text (line by line).

for(i=0; i<20; i++){   //This is to reset coefficients_first.
	
	coefficients_first[i] = '\0';
}
	
	for(i=0; lines[b][i] != '\0'; i++){  //This is to copy lines[b][i] to coefficients_first[i].
	
	coefficients_first[i] = lines[b][i];
	
	}
		
	j=0;
	

	for(i=0; lines[b][i] != '='; i++){   // This is for the equation's left side.
			
		if (isalpha(lines[b][i]) != 0){  // While checking for every element in the equation if it faces any char, takes it as variable to the vaiables array.
		
            variables[j] = lines[b][i];
            j++;
            	
			}
        }
        
	
	
	for(; lines[b][i] != '\0'; i++){  // This is for the equation's right side.
		
		if (isalpha(lines[b][i]) != 0){  // While checking for every element in the equation if it faces any char, takes it as variable to the vaiables array.
		
            variables[j] = lines[b][i];
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
	
	for(i=0; coefficients_first[i] != '\0'; i++){
		
	}
	
	trial = fopen("denemetext.txt", "w");
	
	if(isalpha(coefficients_first[0]) != 0){  //If there is a letter and there isn't any coefficient, it puts "1" in front of it.

		
		fprintf(trial, "%c", '1');
		
			}
	
	for(i=0; i<length_of_coefficients_first; i++){
	
	if (isalpha(coefficients_first[i]) == 0){
		
		fprintf(trial, "%c", coefficients_first[i]);
	}
	
	else if (isalpha(coefficients_first[i]) != 0){
		
		
		if(coefficients_first[i-1] == '-'){
			
			fprintf(trial, "%c%c%c",'1',coefficients_first[i], coefficients_first[i+1]);
			i++;
		}
		
		else if(coefficients_first[i-1] == '+'){
			
			fprintf(trial, "%c%c%c",'1',coefficients_first[i], coefficients_first[i+1]);
			i++;
		}
		
		
		else{
			
			fprintf(trial, "%c", coefficients_first[i]);
		}
	}   
		

}


fclose(trial);
	
	char newline[40];
	
	trial = fopen("denemetext.txt", "r");
	
	fscanf(trial,"%s", newline); 
	
	int length_of_newline = strlen(newline); // this is to measure lines' length.
	
	fclose(trial);
	
	p = fopen("lines.txt", "w");            // Here we put "+" instead of "=" in the equation to easily get the coefficients and variables with %f%c method.
	for(i=0; i < length_of_newline; i++){   
		
		if(newline[i] == '='){
			
			newline[i] = '+'; // This is to identify the constant which is left side of the equation.
			
		}
	}
	
	fprintf(p, "%s", newline);   // and writing it to a new file.

	fclose(p);
	
	p = fopen("lines.txt", "a"); // This is to identify the last constant.
	fprintf(p, "%c", '*');
	fclose(p);
	
	p = fopen("lines.txt", "r");
	
	
	for(i=0; i<20; i++){   // This is to reset coefficients_control and variables_control.
	
	coefficients_control[i] = '\0'; 
	variables_control[i] = '\0'; 
}
	
	
	for(i=0; i<length_of_variables + 4; i++){    // reading the new equation from the new file and get %f for coefficients and get %c for their variables.
	
fscanf(p,"%f%c", &coefficients_control[i], &variables_control[i]);  

if(variables_control[i] == '*'){
	break;
}
	}
	
fclose(p);

int length_of_all_the_variables = strlen(all_the_variables);


int the_count; // This is for counting if the variables[j] and all_the_variables[i] matches or not.
int the_another_count=0;


for(i=0; all_the_variables[i] != '\0'; i++){ 
	
	the_count=0;
	
	for(j=0; variables_control[j] != '*'; j++){
		
		if(all_the_variables[i] == variables_control[j]){  // If they match, add the coefficient to the matrix.
			
			matrix[b][i] = coefficients_control[j];   
			the_count=1;
			the_another_count++;	
		}
	
	}
	
	if(the_count != 1){  // If they don't mach, add 0.0 to the matrix.
		
		matrix[b][i] = 0.0;
	}
}

int last_count = 0;

for(j=0; variables_control[j] != '*'; j++){  // It checks whether there is constant on the left side or not.
	
	if(variables_control[j] == '+' || variables_control[j] == '-'){
		
		the_constant_left = coefficients_control[j];
		last_count++;
		
	}
	
}

if(last_count == 1){

matrix[b][i] = coefficients_control[j] - the_constant_left;  // This is to calculate for the last constant.
	
}

else{
	matrix[b][i] = coefficients_control[j];
	
}




}

printf("\n");

for (int j=0;j<length_of_all_the_variables;j++){ //same as line number
        for(int i=0;i<length_of_all_the_variables;i++){ // coefficients, We do not include the result part in the triangle thats why i dont write coeffnum in here.
            if (i>j){ //This continues until it forms a perpendicular triangle in the matrix with zeros.
                float ratio=matrix[i][j]/matrix[j][j]; //this gets the ratio of a coefficient and next line with same coefficient
                for (int k=0;k<length_of_all_the_variables+1;k++){
                    matrix[i][k] = matrix[i][k]-ratio*matrix[j][k]; //in here we will multiply ratio and upper line and subtract them with current line. One of the coefficients turns 0.
                }
                printf("Next step:\n");
                
                for (int i=0;i<length_of_all_the_variables;i++){ //i<line number
        printf("[");
        for (int j=0;j<length_of_all_the_variables+1;j++){ //j<unknown number plus result
            if (j==length_of_all_the_variables){//print result in matrix (last element)
                printf("%.2f", matrix[i][j]);
            }else{//if its not last element this adds blank space.
                printf("%.2f ", matrix[i][j]);
            }
            if (j==length_of_all_the_variables-1){ // Before pirnting result, this adds : sign for better understanding.
                printf(": ");
            }
        }
        printf("]\n");
    }
            
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
    
    
        //Bonus part with printing results
    for (int i=0; i<length_of_all_the_variables+2; i++){ //+1 for checking result
        if (isnan(result[i])){ //checking if its NaN or not
            nanvalue++;
        }
        if (isinf(result[i])){ //checking if its inf (infinite) value or not
            infvalue++;
        }
    }
    
    if (nanvalue == length_of_all_the_variables){                               //if all results have NaN value (0/0)
        printf("This equation has multiple solutions!\n"); //print this
    }else if (infvalue == length_of_all_the_variables + 1){                   //if all results have infinite value (for ex. 7/0)
        printf("This equation has no solutions!\n"); //print this.
    }else{
        printf("RESULTS:\n");//printing results
        for (int i=0;i<length_of_all_the_variables;i++){
            printf("%c is %g\n",all_the_variables[i],result[i]);
        }
    }
    
    remove("denemetext.txt");
    remove("lines.txt");
    
    AfterSolving();
    
    

	return 0;
	
}


static void AfterSolving(){ //This includes recursive function Bonus
	
	int again;
    printf("Do you want to close this program?\n");
    printf("1.Yes\n");
    printf("Your Selection:");
    scanf("%d",&again);
    switch (again) {
        
        case 1:
            break;
        default: //if user selects other than 1 or 2 this function runs again.
            printf("If you want to close the program, please select 1!\n");
            AfterSolving();
    }
}
