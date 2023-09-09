#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int atv, atvF;
    scanf("%d%d", &atv, &atvF);
    double m=((double)atvF/atv)*100;
    if(m<20){
       printf("%.2f%% 4.40%% Pessimo",m); 
    }else if(m<40){
       printf("%.2f%% 31.65%% Ruim",m);
    }else if(m<60){
       printf("%.2f%% 56.82%% Bom",m);
    }else if(m<80){
       printf("%.2f%% 80.00%% Muito Bom",m);
    }else if(m<100){
       printf("%.2f%% 94.00%% Excelente",m);
    }
	return 0;
}