#include <stdio.h>
int verificaValidadeMatriz(int matriz[]){
    int contador[4]={0}, soma=0;
    for(int i=0;i<4;i++){
        if(matriz[i]>=0 && matriz[i]<4 && contador[matriz[i]]==0) contador[matriz[i]]++;
    }
    if(contador[0] && contador[1] && contador[2] && contador[3]) return 1;
    return 0;
}

int main(){
    int altura, largura, saida=0;
    scanf("%d %d", &altura, &largura);
    int matriz[altura][largura];
    for(int i=0;i<altura;i++){
        for(int d=0;d<largura;d++){
            scanf("%d", &matriz[i][d]);
        }
    }
    for(int i=0;i<altura;i++){
        for(int d=0;d<largura;d++){
            int matrixDoisPDois[4]={matriz[i][d], matriz[i][d+1], matriz[i+1][d], matriz[i+1][d+1]};
            saida+=verificaValidadeMatriz(matrixDoisPDois);
        }
    }
    printf("%d", saida);
    /*
    2 x 2 compostos por 0, 1, 2, e 3
    */
    return 0;
}
