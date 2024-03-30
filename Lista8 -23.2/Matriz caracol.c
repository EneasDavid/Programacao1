#include <stdio.h>

int main(){
    int i=0, d=0, altura=0, largura=0, tamanho;
    scanf("%d", &tamanho);
    int matriz[tamanho][tamanho];
    int tamanhoProfundidade=tamanho;
    while(altura<=tamanho && largura<=tamanho){
       for(i=altura;i<tamanhoProfundidade;i++){
            scanf("%d",&matriz[i][d]);
            //printf("B-[%d:%d]:%d\n",i,d,matriz[i][d]);
        }
        i--;
        largura++;
        for(d=largura;d<tamanhoProfundidade;d++){
            scanf("%d",&matriz[i][d]);
            //printf("D-[%d:%d]:%d\n",i,d,matriz[i][d]);
        }
        d--;
        altura++;
        for(i-=1;i>=altura-1;i--){
            scanf("%d",&matriz[i][d]);
            //printf("C-[%d:%d]:%d\n",i,d,matriz[i][d]);
        }
        i++;
        for(d-=1;d>=largura;d--){
            scanf("%d",&matriz[i][d]);
            //printf("E-[%d:%d]:%d\n",i,d,matriz[i][d]);
        }
        d++;
        tamanhoProfundidade--;
    }
    for(i=0;i<tamanho;i++){
        for(d=0;d<tamanho;d++){
            printf("%d\n", matriz[i][d]);
        }
    }
    return 0;
}