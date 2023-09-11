#include <stdio.h>
#define MAX 4

void trocarElementos(double *elementoAnterior, double *elementoNovo){
    double variavelTemporaria = *elementoAnterior;
    *elementoAnterior = *elementoNovo;
    *elementoNovo = variavelTemporaria;
}
//Verificar
void po(double meuArray[],int posicao, int loop){
    if(posicao < MAX-1){
        if(meuArray[loop] > meuArray[posicao]){
            return trocarElementos(&meuArray[posicao], &meuArray[loop]);
        }
        return po(meuArray, loop, posicao+1);
    }
}
void ordenaArray(double meuArray[], int loop){
    if(loop < MAX-1){
        return po(meuArray, loop, loop+1);
    }
    return ordenaArray(meuArray, loop+1);
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
    printf("%.2lf\n%.2lf\n%.2lf\n%.2lf",altura[0],altura[1],altura[2],altura[3]);
    return 0;
}
