#include <stdio.h>

void acidez(double ph){
    if(ph<7){
        printf("ACIDA\n");
    }else if(ph>7){
        printf("BASICA\n");
    }else{
        printf("NEUTRA\n");
    }
}

myWhile(){
    double entrada;
    scanf("%lf", &entrada);
    if(entrada==-1) return 0;
    acidez(entrada);
    myWhile();
}

int main(){
    myWhile();
    return 0;
}