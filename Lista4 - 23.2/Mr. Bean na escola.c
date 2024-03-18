#include <stdio.h>
#include <math.h>
#define max_size 10000000
int eh_primo(int entrada, int i) {
    if(entrada == 2) {
        return 1;
    }
    if(entrada < 2 || entrada % 2 == 0) {
        return 0;
    }
    if(i>sqrt(entrada)) {
        return 1;
    }
    if(entrada % i == 0) {
        return 0;
    }
    return eh_primo(entrada, i+1);
}

int acharPrimoAnterior(int valor, int contador){
    if(contador==0) return 0;
    if(eh_primo(contador,2)) return contador;
    return acharPrimoAnterior(valor, contador-1);
}

void myWhile(int entrada, int *par, int *impar){
    if(entrada==0) return ;
    int valor;
    scanf("%d", &valor);
    if (!(valor%2)) {
        if (valor> *par) *par=valor;
    }else{
        if(valor< *impar) *impar=valor;
    }
    myWhile(entrada-1, par, impar);
}

int main(){
    int entrada, maiorPar=0, menorImpar=max_size;
    scanf("%d", &entrada);
    myWhile(entrada, &maiorPar, &menorImpar);
    if(maiorPar==0) printf("Sem numeros pares\n");
    else printf("Maior par: %d\nPrimo anterior ao maior: %d\n", maiorPar, acharPrimoAnterior(maiorPar,maiorPar-1));
    if(menorImpar==max_size) printf("Sem numeros impares\n");
    else printf("Menor impar: %d\nPrimo anterior ao menor: %d\n", menorImpar, acharPrimoAnterior(menorImpar,menorImpar-1));
    return 0;
}