#include <stdio.h> 
#include <string.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>


int main(){
	
	
	char lines[20][20];
	FILE *p;
	p = fopen("text.txt", "r");
	int i = 0;
	
	 while(!feof(p)){
	fscanf(p,"%s",lines[i]);
	printf("%s\n", lines[i]);
	i++;
	}
	
	fclose(p);
	
	char variables[8];
	
	//printf("%s", first[0]);
	
	//printf("%c", firstline[1]);
	
	
	int j = 0;
	int b = 0;
	
	for(i=0; lines[b][i] != '='; i++){
			
		if (isalpha(lines[b][i]) != 0){
		
            printf("this is one of the variables %c which is left side of the equation\n", lines[b][i]);
            variables[j] = lines[b][i];
            printf("this is the %d. variable = %c which is left side of the equation\n", j, variables[j]);
            j++;
            	
			}
        }
        
        
		//printf("%c\n", firstline[i]);
	
	
	for(; lines[b][i] != '\0'; i++){
		
		if (isalpha(lines[b][i]) != 0){
		
            printf("this is one of the variables %c which is right side of the equation\n", lines[b][i]);
            variables[j] = lines[b][i];
            printf("this is the %d. variable = %c which is right side of the equation\n", j, variables[j]);
            j++;
        }
		
	}
	
	float coefficients_control[20];
	char variables_control[20];
	char a[20];
	int length_of_variables = strlen(variables);
	
	char newline[20];
	strcpy(newline, lines[0]);
	printf("%s\n", lines[0]);
	printf("%s\n", newline);
	int length_of_newline = strlen(newline);
	
	p = fopen("mamo.txt", "w");
	for(i=0; i < length_of_newline; i++){
		
		if(newline[i] == '='){
			
			newline[i] = ' ';
			
		}
	}
	
	fprintf(p, "%s", newline);

	fclose(p);
	
	p = fopen("mamo.txt", "r");
	
	
	for(i=0; i<length_of_variables+1; i++){
	
fscanf(p,"%f%c", &coefficients_control[i], &variables_control[i]);
printf("%f%c\n",coefficients_control[i], variables_control[i]);

	}
	
fclose(p);

FILE *p2;
p2 = fopen("new.txt", "w");
for(i = 0; i<length_of_variables+1; i++){
	
	fprintf(p2,"%f%c\n",coefficients_control[i], variables_control[i]);
	
}

fclose(p2);

char control[20][20];

p2 = fopen("new.txt", "r");

i=0;
 while(!feof(p2)){
	
	fscanf(p2, "%s", control[i]);
	printf("%s\n", control[i]);
	i++;	
	
	}

//for(i=0; variables[i] != '\0'; i++){
//	printf("%c\n", variables[i]);
//}
b=0;

for(i=0; control[b][i] != '\0'; i++){
	
	int length_of_controlb = strlen(control[b]);
	int t = length_of_controlb - 1;
	
	printf("%c ", control[b][i]);
	
}

printf("%f", atof(control[0]));

	return 0;
	
}
