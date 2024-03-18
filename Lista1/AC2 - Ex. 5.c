#include <stdio.h>

int myWhile(int entrada, int dias, int horas, int minutos, int segundos){
    if(entrada/86400){
        dias+=entrada/86400;
        return myWhile(entrada%86400, dias, horas, minutos, segundos);
    }else if(entrada/3600){
        horas+=entrada/3600;
        return myWhile(entrada%3600, dias, horas, minutos, segundos);
    }else if(entrada/60){
        minutos+=entrada/60;
        return myWhile(entrada%60, dias, horas, minutos, segundos);
    }
    segundos+=entrada;
    printf("%d\n%d\n%d\n%d\n", dias, horas, minutos, segundos);
    return 0;
}
int main(){
    int periodo;
    scanf("%d", &periodo);
    myWhile(periodo, 0, 0, 0, 0);
    return 0;
}

/*
FORMATO DE SAIDA

Número de dias   | d
Número de horas  | h
Número de minutos| m
Número de segundo| s

*/