//
//  main.c
//  newnewp3
//
//  Created by Ali Yiğit Taş on 15.05.2022.
// test

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x[3] = {1,0,0};
int y[3] = {5,2,0};
int z[3] = {3,1,0};
int results[3] = {-8,3,7};
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
        if (x[i]==0){
            printf("");
        }else if (x[i]==1){
            printf("x");
        }else if (x[i]==-1){
            printf("-x");
        }else {
            printf("%dx", x[i]);
        }
        
        //Print y coefficient
        if (y[i]==0){
            printf("");
        }else if (y[i]==1){
            printf("+y");
        }else if (y[i]==-1){
            printf("-y");
        }else if (x[i]==0){
            printf("%dy",y[i]); //if there is no x program does not print + sign before y if its positive.
        }else {
            printf("%+dy", y[i]);
        }
        
        //Print z coefficient
        if (z[i]==0){
            printf("");
        }else if (z[i]==1){
            printf("+z");
        }else if (z[i]==-1){
            printf("-z");
        }else if (x[i]==0 && y[i]==0){
            printf("%dz",z[i]); //if there is no x program does not print + sign before z if its positive.
        }else {
            printf("%+dz", z[i]);
        }
        
        //Print result of equation
        if (!(x[i]==0 && y[i]==0 && z[i]==0)){
            printf("=%d\n", results[i]);
        }
        
    }
}

static void FirstStep3unk(){
    printf("First Step:\n");
    for (int i=0;i<3;i++){
        printf("[%d %d %d : %d]\n", x[i],y[i],z[i],results[i]);
    }
}

static void Solve3unk(){
    printf("Second Step:\n");
    
    mx[0] = x[0] * x[1];                   //İlk satır
    my[0] = y[0] * x[1];                   //ikinci satırdaki
    mz[0] = z[0] * x[1];                   //x katsayısı ile çarpıldı.
    mresults[0] = results[0] * x[1];       //Yazdırılmaması için farklı değişkene atandı.
    
    
    x[1] = (x[1] * x[0]) - mx[0];                          //İkinci satır ilk satırdaki
    y[1] = (y[1] * x[0]) - my[0];                          //x katsayısı ile çarpıldı.
    z[1] = (z[1] * x[0]) - mz[0];                          //ilk satırdan çıkarıldı.
    results[1] = (results[1] * x[0]) - mresults[0];        // Yazdırılacak.

    
    
    mx[0] = x[0] * x[2];                   //1. satır
    my[0] = y[0] * x[2];                   //3. satırdaki
    mz[0] = z[0] * x[2];                   //x katsayısı ile çarpıldı.
    mresults[0] = results[0] * x[2];       //Yazdırılmaması için farklı değişkene atandı.
    
    
    
    x[2] = (x[2] * x[0]) - mx[0];                          //3. satır ilk satırdaki
    y[2] = (y[2] * x[0]) - my[0];                          //x katsayısı ile çarpıldı.
    z[2] = (z[2] * x[0]) - mz[0];                          //1. satırdan çıkarıldı.
    results[2] = (results[2] * x[0]) - mresults[0];        // Yazdırılacak.
    
    
    for (int i=0;i<3;i++){
        printf("[%d %d %d : %d]\n", x[i],y[i],z[i],results[i]);
    }
    printf("\n");
    
    printf("Third Step:\n");
    
    //There is no need to multiply x with y[2] because its already zero in both lines.
    
    my[1] = y[1] * y[2];                    //2. satır 3. satırdaki
    mz[1] = z[1] * y[2];                    //y katsayısı ile çarpıldı.
    mresults[1] = results[1] * y[2];        //Yazdırılmaması için farklı değişkene atandı.
    
    
    y[2] = (y[2] * y[1]) - my[1];                     //3. satır ve 2. satır y değeri çarpıldı
    z[2] = (z[2] * y[1]) - mz[1];                     //3. satırdan
    results[2] = (results[2] * y[1]) - mresults[1];   //2. satır çıkarıldı.
    
    
    for (int i=0;i<3;i++){
        printf("[%d %d %d : %d]\n", x[i],y[i],z[i],results[i]);
    }
    printf("\n");
    
    rsltz = results[2] / z[2];
    rslty = (results[1] - (z[1]*rsltz)) / y[1];
    rsltx = (results[0] - (z[0]*rsltz) - (y[0]*rslty)) / x[0];
    
    if (x[2] ==0 && y[2] ==0 && z[2] ==0 && results[2]==0){
        printf("This equation has multiple solutions! This is one of them:\n");
        printf("x is %f\n",rsltx);
        printf("y is %f\n",rslty);
        printf("z is %f\n",rsltz);
    }else if (x[2] ==0 && y[2] ==0 && z[2] ==0 && results[2]!=0){
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
        nx[i] = x[i];
        ny[i] = y[i];
        nz[i] = z[i];
        nresults[i] = results[i];
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
                x[i] = nx[i];
                y[i] = ny[i];
                z[i] = nz[i];
                results[i] = nresults[i];
            }
            main();
        case 2:
            break;
        default:
            printf("Please select Yes or No.\n");
            AfterSolving();
    }
}
