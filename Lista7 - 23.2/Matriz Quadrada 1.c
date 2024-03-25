#include <stdio.h>

int main(){
    int valor;
    while(scanf("%d", &valor)!=0){
        if(valor==0) return 0;
        int matriz[valor][valor];
        for(int i=0;i<valor;i++){
            for(int d=0;d<valor;d++){
                matriz[i][d]=1;
            }
        }
        int i, d, largura=valor-1;
        for(i=0; i<valor;i++){
            for(d=0;d<largura;d++){
                if (i==0 || i==largura || d==0 || d==largura){
                    printf("%d ", matriz[i][d]);
                    continue;
                }
                else if(i<d) matriz[i][d]+=matriz[i][d+1];
                else if(valor%2 && i==valor>>1 && d==valor>>1) matriz[i][d]+=matriz[i][d-1];
                else matriz[i][d]+=matriz[i+1][d];
                printf("%d ", matriz[i][d]);
            }
            printf("%d\n", matriz[i][d]);
        }
        printf("\n");
    }
}