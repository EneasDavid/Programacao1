#include <stdio.h>
void eTriangular(int numero, int laco){
    if(laco<numero){
        if(laco*(laco+1)*(laco+2)==numero){
            printf("%d * %d * %d = %d\nVerdadeiro",laco,(laco+1),(laco+2),numero);
            return 0;
        }
        return eTriangular(numero, laco+1);
    }
    printf("Falso");
    return 0;
}

int main() {
    int entrada;
    scanf("%d", &entrada);
    eTriangular(entrada,1);
	return 0;
}