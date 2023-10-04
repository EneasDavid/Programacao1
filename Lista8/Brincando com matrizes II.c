#include <stdio.h>
int main() {
    int tamanho=3, matriz[tamanho][tamanho], menor=999999, somaDiagonal=0, totalMatriz=0, positivos=0;
    for (int i=0; i<tamanho; i++) {
        for (int j=0; j<tamanho; j++) {
            scanf("%d", &matriz[i][j]);
            if(matriz[i][j]>0){
             totalMatriz+=matriz[i][j];
             positivos++;
            }
            if (i!=j)somaDiagonal+=matriz[i][j];
            if (matriz[i][j]<menor)menor=matriz[i][j];
        }
    }
    double media=(double)totalMatriz/(double)(positivos);
    int delta=(menor%2==0)?1:0;
    printf("%.2lf %d %d %d\n", media, menor, delta, somaDiagonal);
    return 0;
}