#include <stdio.h>

int main(){
    int valor;
    while(scanf("%d", &valor)!=0){
        int matriz[valor][valor];
        for(int i=0; i<valor;i++){
            for(int d=0;d<valor;d++){
                scanf("%d", &matriz[i][d]);
            }
        }
        int i, d, largura=valor-1;
        for(i=0; i<valor;i++){
            for(d=0;d<largura;d++){
                printf("%d ", i+1);
            }
            printf("%d\n", i+1);
        }
        printf("\n");
    }
}