#include <stdio.h>

int main() {
    int tamanho=3, matriz[tamanho][tamanho], maior=-1, somaDiagonal=0, totalMatriz=0;

    for (int i=0; i<tamanho; i++) {
        for (int j=0; j<tamanho; j++) {
            scanf("%d", &matriz[i][j]);
            totalMatriz+=matriz[i][j];
            if (i==j) {
                somaDiagonal+=matriz[i][j];
            }
            if (matriz[i][j]>maior) {
                maior=matriz[i][j];
            }
        }
    }

    double media=(double)totalMatriz/(double)(tamanho*tamanho);
    int delta=(maior>0)?1:((maior<0)?-1:0);
    printf("%.2lf %d %d %d\n", media, maior, delta, somaDiagonal);

    return 0;
}
