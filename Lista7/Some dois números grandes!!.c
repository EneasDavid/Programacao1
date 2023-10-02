#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10001

char* organiza(char *resultado, int tamanho){
    if (resultado[0]=='0') {
        char *novoResultado=(char*)malloc(tamanho);
        novoResultado[tamanho-1]='\0';
        for (int i=0; i<tamanho; i++) {
            novoResultado[i]=resultado[i+1];
        }
        resultado = novoResultado;
    }
    return resultado;
}

char* ajustaTamanhoArray(char *myArray, int *tamanho) {
    while (*tamanho > 1 && myArray[0] == '0') {
        myArray++;
        (*tamanho)--;
    }
    return myArray;
}

char* somaGrandes(char myArray[], char myArrayDois[], int maior) {
    char *resultado=(char*) malloc(maior+2);
    resultado[maior+1]='\0';
    int restoSoma=0, tamanhoUm=strlen(myArray)-1, tamanhoDois=strlen(myArrayDois)-1;

    for(int i=0; i<maior; i++) {
        int digito1=i<strlen(myArray)?myArray[tamanhoUm-i]-'0':0;
        int digito2=i<strlen(myArrayDois)?myArrayDois[tamanhoDois-i]-'0':0;
        int soma=digito1+digito2+restoSoma;
        restoSoma=soma/10;
        resultado[maior-i]=soma%10+'0';
    }
    resultado[0]=restoSoma+'0';
    resultado=organiza(resultado, maior+1);
    resultado=ajustaTamanhoArray(resultado, &maior);
    return resultado;
}

int main() {
    char myArrayUm[MAX], myArrayDois[MAX];
    scanf("%s %s", myArrayUm, myArrayDois);
    int maximoTam=strlen(myArrayUm)>strlen(myArrayDois)?strlen(myArrayUm):strlen(myArrayDois);
    char *resultado=somaGrandes(myArrayUm, myArrayDois, maximoTam);
    printf("%s\n", resultado);
    free(resultado);
    return 0;
}
