#include <stdio.h>
#define MAX 4

void trocaElementos(double myArray[], int local) {
    double temporario;
    temporario=myArray[local];
    myArray[local]=myArray[local+1];
    myArray[local+1]=temporario;
}
void passagemArray(double myArray[], int tamanho, int local) {
    if (local<tamanho-1) {
        if (myArray[local]>myArray[local+1]) {
            trocaElementos(myArray, local);
        }
        passagemArray(myArray, tamanho, local+1);
    }
}
void ordenaArray(double myArray[], int tamanho) {
    if (tamanho>0) {
        passagemArray(myArray, tamanho, 0);
        ordenaArray(myArray, tamanho-1);
    }
    return; 
}
void myFor(double meuArray[], int loop) {
    if (loop<MAX) {
        double entrada;
        scanf("%lf", &entrada);
        meuArray[loop]=entrada;
        myFor(meuArray, loop+1);
    }
}
int main() {
    double altura[MAX];
    myFor(altura, 0);
    ordenaArray(altura, MAX);
    printf("%.2lf\n%.2lf\n%.2lf\n%.2lf", altura[0], altura[2], altura[3], altura[1]);  // Imprime o array ordenado
    return 0;
}