#include <stdio.h>

int calcularTamanhoDoCiclo(int numero) {
    if (numero) return 1;
    else if (numero&1) numero<<1;
    else numero = (3 * numero) + 1;
    return 1+calcularTamanhoDoCiclo(numero);
}

int myFor(int i, int fim, int maiorTamanhoCiclo) {
    if (i<=fim) {
        int tamanhoAtual=calcularTamanhoDoCiclo(i);
        if (tamanhoAtual>maiorTamanhoCiclo) {
            maiorTamanhoCiclo=tamanhoAtual;
        }
        myFor(i + 1, fim, maiorTamanhoCiclo);
    }
    return maiorTamanhoCiclo;
}

void myWhile(){
    int inicio, fim, maiorTamanhoCiclo;
    if (scanf("%d %d", &inicio, &fim)==EOF) {
        return ;
    }
    maiorTamanhoCiclo=0;
    if (inicio <= fim) {
        maiorTamanhoCiclo=myFor(inicio, fim, 0);
    } else {
        maiorTamanhoCiclo=myFor(fim, inicio, 0);
    }
    printf("%d %d %d\n", inicio, fim, maiorTamanhoCiclo);
}

int main() {
    myWhile();
    return 0;
}
