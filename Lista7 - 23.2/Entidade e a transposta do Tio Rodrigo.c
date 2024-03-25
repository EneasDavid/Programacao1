#include <stdio.h>

int main(){
    int tamanho;
    scanf("%d", &tamanho);
    int matriz[tamanho][tamanho], matrizAux[tamanho][tamanho];
    for(int i=0;i<tamanho;i++){
        for(int d=0;d<tamanho;d++){
            scanf("%d", &matriz[i][d]);
            matrizAux[d][i]=matriz[i][d];
        }
    }
    int fixo=tamanho-1;
    for(int i=0;i<tamanho;i++){
        for(int d=0;d<tamanho;d++){
            if(i==d) matrizAux[i][d]=matriz[fixo-i][fixo-d];
    	    if (i+d==fixo) matrizAux[i][d]=matriz[fixo-i][fixo-d]<<1;
        }
    }
    int i,d;
    for(i=0;i<tamanho;i++){
        for(d=0;d<fixo;d++){
            printf("%d ", matrizAux[i][d]);
        }
        printf("%d\n", matrizAux[i][d]);
    }
    return 0;
}