#include <stdio.h>
#define MAX 4

void printar(double meuArray[], int loop){
    if(loop < MAX){
        printf("%.2lf\n", meuArray[loop]);
        printar(meuArray, loop+1);
    }
}

void trocarElementos(double *elementoAnterior, double *elementoNovo){
    double variavelTemporaria = *elementoAnterior;
    *elementoAnterior = *elementoNovo;
    *elementoNovo = variavelTemporaria;
}

void ordenaArray(double meuArray[], int loop){
    if(loop < MAX-1){
        if(meuArray[loop] > meuArray[loop+1]){
            trocarElementos(&meuArray[loop], &meuArray[loop+1]);
        }
        ordenaArray(meuArray, loop+1);
    }
}

void myFor(double meuArray[], int loop) {
    if (loop < MAX) {
        double entrada;
        scanf("%lf", &entrada);
        meuArray[loop] = entrada;
        myFor(meuArray, loop+1);
    }
}

int main() {
    double altura[MAX];
    myFor(altura, 0);
    ordenaArray(altura, 0);
    printar(altura, 0);
    return 0;
}
