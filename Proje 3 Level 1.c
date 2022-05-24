#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int Selection;

float solve1(float a, float b) {

    return -(b / a);
}

float solve2(float a, float b, float c) {

    return ((c - b) / a);
}



int main(void) {
    float a = 0, b = 0, c = 0;

jump1:
    printf("Please select the equation type: \n");
    printf("1. ax + b = 0 \n");
    printf("2. ax + b = c \n");
    printf("Your selection: ");
    scanf("%d", &Selection);
    system("cls||clear");


    switch (Selection) {
    case 1:

        printf("You selected ax + b = 0 \n");
        printf("Enter the value of a: ");
        scanf("%f", &a);

        printf("Enter the value of b: ");
        scanf("%f", &b);


        if (a == 0) {
            system("cls||clear");
            printf("There is no solution for this equation. \n\n");
            goto jump1;
        }
        else {
            printf("Your equation is: %.5fx + %.5f = 0 \n", a, b);
            float solution = solve1(a, b);
            printf("The value of x is: %.5f", solution);
            break;
        }

    case 2:

        printf("You selected ax + b = c \n");
        printf("Enter the value of a: ");
        scanf("%f", &a);

        printf("Enter the value of b: ");
        scanf("%f", &b);

        printf("Enter the value of c: ");
        scanf("%f", &c);

        if (c == 0) {
            system("cls||clear");
            printf("Please select the right equation type!! \n\n");
            goto jump1;
        }
        else {
            printf("Your equation is: %.5fx + %.5f = %.5f \n", a, b, c);
            float solution = solve2(a, b, c);
            printf("The value of x is: %.5f", solution);
            break;
        }

    }

}