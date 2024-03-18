#include <stdio.h>
#define MAX 100

void imprimir(int array[], int posicao, int tamanho) {
    if (posicao==tamanho) {
        printf("%d\n", array[posicao]);
        return;
    }
    printf("%d ", array[posicao]);
    imprimir(array, posicao+1, tamanho);
}

void soma(int arrayInvertido[], int arrayImparPar[], int arraySoma[], int contador){
    if(contador<0) return;
    soma(arrayInvertido, arrayImparPar, arraySoma, contador-1);
    arraySoma[contador]=arrayInvertido[contador]+arrayImparPar[contador];
}

void pares(int array[], int arrayParImpar[], int contador, int contadorNovo, int limite) {
    if(contador==limite) return;
    if (contador%2) {
        arrayParImpar[contadorNovo]=array[contador];
        contadorNovo++;
    }
    pares(array, arrayParImpar, contador+1, contadorNovo, limite);
}

void imparesPares(int array[], int arrayParImpar[], int contador, int contadorNovo, int limite) {
    if(contador==limite){
        pares(array, arrayParImpar, 0, contadorNovo, limite);
        return;
    }
    if (!(contador%2)) {
        arrayParImpar[contadorNovo]=array[contador];
        contadorNovo++;
    }
    imparesPares(array, arrayParImpar, contador+1, contadorNovo, limite);
}

void inversao(int array[], int arrayInverso[], int contador, int contadorInverso){
    if(contador<0) return;
    arrayInverso[contadorInverso]=array[contador];
    inversao(array, arrayInverso, contador-1, contadorInverso+1);
}

void myFor(int contador, int array[]) {
    int entrada;
    if (scanf("%d", &entrada) != EOF) {
        array[contador] = entrada;
        myFor(contador + 1, array);
    } else {
        int arrayInvertido[MAX], arrayParImpar[MAX], arraySoma[MAX];
        inversao(array, arrayInvertido, contador - 1, 0);
        imparesPares(array, arrayParImpar, 0, 0, contador);
        soma(arrayInvertido, arrayParImpar, arraySoma, contador);
        printf("Invert: ");
        imprimir(arrayInvertido, 0, contador-1);
        printf("ParImp: ");
        imprimir(arrayParImpar, 0, contador-1);
        printf("Soma: ");
        imprimir(arraySoma, 0, contador-1);
    }
    return;
}

int main() {
    int array[MAX];
    myFor(0, array);
    return 0;
}
