#include <stdio.h>
void preencherMatriz(int ladoMatriz, int myArray[ladoMatriz][ladoMatriz]){
    for(int i=0;i<ladoMatriz;i++){
        for(int j=0; j<ladoMatriz; j++){
            scanf("%d", &myArray[i][j]);
        }
    }
}
int main(){
    int ladosMatriz;
    scanf("%d", &ladosMatriz);
    if(ladosMatriz==0) printf("Vazia");
    int matriz[ladosMatriz][ladosMatriz], matrizDois[ladosMatriz][ladosMatriz], matrizResultante[ladosMatriz][ladosMatriz];
    int somaDiagonalPrincipal=0, somaDiagonalSecundaria=0;
    preencherMatriz(ladosMatriz, matriz);
    preencherMatriz(ladosMatriz,matrizDois);
    for(int i=0;i<ladosMatriz;i++){
        for(int d=0;d<ladosMatriz;d++){
            matrizResultante[i][d]=matriz[i][d]+matrizDois[i][d];
        }
    }
    for(int i=0;i<ladosMatriz;i++){
        for(int d=0;d<ladosMatriz;d++){
           printf("%d\n", matrizResultante[i][d]);
        }
    }
    return 0;
}