#include <stdio.h>

void bubbleSort(int myArray[], int inicio, int fim){    
    if (inicio<fim){
        if (myArray[inicio]>myArray[inicio+1]){
            int temp=myArray[inicio];
            myArray[inicio]=myArray[inicio+1];
            myArray[inicio+1]=temp;
        }
        bubbleSort(myArray, inicio + 1, fim);
    }
    return;
}

void ordenarArray(int myArray[], int tamanho){
    if (tamanho>0){
        bubbleSort(myArray, 0, tamanho);
        ordenarArray(myArray, tamanho - 1);
    }
    return;
}

void lerArray(int myArray[], int indice, int tamanho){
    if (indice<tamanho){
        scanf("%d", &myArray[indice]);
        lerArray(myArray, indice + 1, tamanho);
    }
    return;
}

void imprimirArray(int myArray[], int indice, int tamanho){
    if (indice<tamanho){
        printf("%d ", myArray[indice]);
        imprimirArray(myArray, indice + 1, tamanho);
    }
    return;
}

int somarArray(int myArray[], int posicao, int fim, int soma){
    if (posicao<fim) {
        soma=soma+ myArray[posicao];
        return somarArray(myArray, posicao+1, fim, soma);
    }
    return soma;
}

void processarDados(int myArray[], int posicao, int quantidade){
    if (posicao<quantidade){
        int dados[4];
        lerArray(dados, 0, 4);
        ordenarArray(dados, 3);
        myArray[posicao] = somarArray(dados, 1, 4, 0);
        processarDados(myArray, posicao + 1, quantidade);
    }
    return;
    
}

int main(){
    int myArrayGerais[6];
    int forca, destreza, constituicao, sabedoria, inteligencia, carisma;
    processarDados(myArrayGerais, 0, 6);
    ordenarArray(myArrayGerais, 5);
    scanf("%d %d %d %d %d %d", &forca, &destreza, &constituicao, &sabedoria, &inteligencia, &carisma);
    printf("For = %d\n", myArrayGerais[6 - forca]);
    printf("Des = %d\n", myArrayGerais[6 - destreza]);
    printf("Con = %d\n", myArrayGerais[6 - constituicao]);
    printf("Sab = %d\n", myArrayGerais[6 - sabedoria]);
    printf("Int = %d\n", myArrayGerais[6 - inteligencia]);
    printf("Car = %d\n", myArrayGerais[6 - carisma]);
    return 0;
}