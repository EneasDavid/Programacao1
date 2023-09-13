#include <stdio.h>


void inverter(int meuArray[], int loop){
    if(loop>-1){
        printf("%d ", meuArray[loop]);
        inverter(meuArray,loop-1);
    }
    return;
}

void preencher(int meuArray[], int finalArray, int loop){
    int entrada;
    if(loop<finalArray){
        scanf("%d", &entrada);
        meuArray[loop]=entrada;
        preencher(meuArray, finalArray, loop+1);
    }
    return;
}

int main() {
    int tamanho;
    scanf("%d", &tamanho);
    int vetor[tamanho];
    preencher(vetor, tamanho, 0);
    inverter(vetor, tamanho-1);
	return 0;
}