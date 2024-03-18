#include <stdio.h>
#include <math.h>

void printar(int array[], int tamanho, int posicao) {
    if(posicao<tamanho){
        printf("%d ", array[posicao]);
        printar(array, tamanho, posicao + 1);
    }
}

int converterPraBinario(int numero, int tamanho, int resultado[]){
    if(tamanho>0){
        resultado[tamanho-1] = numero%2;
        return converterPraBinario(numero/2, tamanho-1, resultado);
    }
    if(numero>=1){
        return 1;
    }
    printar(resultado, tamanho, 0);
    return 0;
}

void converterPraDecimal(int myArray[], int tamanho, int exponencial, double *decimal) {
    if (tamanho > 0) {
        myArray[tamanho-1] = myArray[tamanho-1] * pow(2, exponencial);
        *decimal += myArray[tamanho-1];
        converterPraDecimal(myArray, tamanho - 1, exponencial + 1, decimal);
    }
}

void preencher(int array[], int tamanhoArray, int posicao) {
    if (posicao < tamanhoArray) {
        scanf("%d", &array[posicao]);
        preencher(array, tamanhoArray, posicao + 1);
    }
}


int main() {
    int tamanhoArray;
    double valorUmDecimal=0, valorDoisDecimal=0;
    scanf("%d", &tamanhoArray);
    int numeroBinarioUm[tamanhoArray], numeroBinarioDois[tamanhoArray], numeroBinarioSoma[tamanhoArray], somaPraBinario[tamanhoArray];
    preencher(numeroBinarioUm, tamanhoArray, 0);
    preencher(numeroBinarioDois, tamanhoArray, 0);
    converterPraDecimal(numeroBinarioUm, tamanhoArray, 0, &valorUmDecimal);
    converterPraDecimal(numeroBinarioDois, tamanhoArray, 0, &valorDoisDecimal);
    int overflow = converterPraBinario((int)(valorUmDecimal + valorDoisDecimal), tamanhoArray, somaPraBinario);
    
    if (overflow==1) {
        printf("OVERFLOW\n");
    }else{
        printar(somaPraBinario, tamanhoArray, 0);
    }
    return 0;
}
