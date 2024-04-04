#include <stdio.h>
#include <math.h>

void ler(int tamanhoMatriz, int matriz[tamanhoMatriz][tamanhoMatriz], int *indexI, int *indexD, int metade){
    for(int i=0; i<tamanhoMatriz; i++){
        for(int d=0; d<tamanhoMatriz; d++){
            int valor;
            scanf("%d", &valor);
            if(valor==1){
                *indexI=i;
                *indexD=d;
                matriz[metade][metade]=1;
                return ;
            }
        }
    }
    return ;
}
int main(){
    int tamanhoMatriz;
    scanf("%d", &tamanhoMatriz);
    int metade=tamanhoMatriz>>1;
    int matriz[tamanhoMatriz][tamanhoMatriz], indexI, indexD;
    for(int i=0; i<tamanhoMatriz; i++){
        for(int d=0; d<tamanhoMatriz; d++){
            matriz[i][d]=0;
        }
    }
    ler(tamanhoMatriz, matriz, &indexI, &indexD, metade);
   
    int valor=sqrt(pow((metade-indexI),2))+sqrt(pow((metade-indexD),2));
    printf("%d\n", valor);
    for(int i=0; i<tamanhoMatriz; i++){
        for(int d=0; d<tamanhoMatriz; d++){
            printf("%d ", matriz[i][d]);
        }
        printf("\n");
    }
    return 0;
}

