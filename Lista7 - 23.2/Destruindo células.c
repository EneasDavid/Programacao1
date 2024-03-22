#include <stdio.h>

int main(){
    int alturaMatriz, larguraMatriz, matar, cont=0;
    scanf("%d %d", &alturaMatriz, &larguraMatriz);
    int matriz[alturaMatriz][larguraMatriz];
    for(int i=0;i<alturaMatriz;i++){
        for(int d=0;d<larguraMatriz;d++){
            scanf("%d", &matriz[i][d]);
            if(matriz[i][d]==1) cont+=1;
        }
    }
    scanf("%d", &matar);
    if(!(alturaMatriz%2)){
    for(int i=0;i<larguraMatriz;i++){
        for(int d=0;d<alturaMatriz;d++){
            if(matriz[d][i]==1 && matar){
                matriz[d][i]=0;
                matar--;
                cont--;
            } 
        }
    }
    }else{
    for(int i=0;i<alturaMatriz;i++){
        for(int d=0;d<larguraMatriz;d++){
            if(matriz[i][d]==1 && matar){
                matriz[i][d]=0;
                matar--;
                cont--;
            } 
        }
    }   
    }
    int i, d, largura=larguraMatriz-1;;
    for(i=0;i<alturaMatriz;i++){
        for(d=0;d<largura;d++){
            printf("%d ", matriz[i][d]);
        }
        printf("%d\n", matriz[i][d]);
    }
    printf("%d %d", matar, cont);
    return 0;
}