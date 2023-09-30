#include <stdio.h>
#include <string.h>
#define MAX 255

int main() {
    int dias, qtnTotal=0;
    double valorTotal=0;
    char frutas[MAX];

    scanf("%d", &dias);

    for(int i=1; i<=dias; i++) {
        double valor;
        scanf("%lf", &valor);
        getchar(); // remove o caractere de nova linha deixado pelo scanf anterior
        fgets(frutas, MAX, stdin);
        int frutasDias=1;
        for(int i=0; i<strlen(frutas); i++) {
            if(frutas[i]==' ') frutasDias++;
        }
        qtnTotal+=frutasDias;
        valorTotal+=valor;
        printf("dia %d: %d kg\n", i, frutasDias);
    }
    printf("%.2lf kg por dia\nR$ %.2lf por dia", (double)qtnTotal/dias, valorTotal/dias);
    return 0;
}