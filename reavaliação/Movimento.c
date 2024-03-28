#include <stdio.h>

void imprimirCoordenadasEspelhadas(int ladoMatriz, int primeira) {
    char caracterVez;
    if (scanf("%c", &caracterVez)==EOF) return;
    if (caracterVez=='('){
        int posicaoUm, posicaoDois;
        scanf("%d,%d", &posicaoUm, &posicaoDois);
        int espelhado=ladoMatriz-posicaoDois+1;

        if (!primeira) {
            printf(",");
        }
        printf("(%d,%d)", posicaoUm, espelhado);
        primeira = 0;

        if (scanf("%c", &caracterVez)!=EOF) {
            if (caracterVez==',') printf(",");
            ungetc(caracterVez, stdin);
        }
    }
    imprimirCoordenadasEspelhadas(ladoMatriz, primeira);
}

int main() {
    int ladoMatriz;
    scanf("%d", &ladoMatriz);
    while (getchar()!='\n');
    imprimirCoordenadasEspelhadas(ladoMatriz, 1);
    return 0;
}
