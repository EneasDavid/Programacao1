#include <stdio.h>
void imprimir(int contador, int impar, int array[]){
    if(contador>0) imprimir(contador-1, impar, array);
    if(impar) printf("impar[%d] = %d\n", contador, array[contador]);
    else printf("par[%d] = %d\n", contador, array[contador]);
};

void preencherArray(int contador, int qtnImpar, int qtnPar, int impar[], int par[]){
    if(!contador){
        if(qtnImpar>0) imprimir(qtnImpar-1, 1, impar);
        if(qtnPar>0) imprimir(qtnPar-1, 0, par);
        return;
    }
    if(qtnImpar==5){
        imprimir(4, 1, impar);
        qtnImpar=0;
    }  
    if(qtnPar==5){ 
        imprimir(4, 0, par);
        qtnPar=0;
    }
    int entrada;
    scanf("%d", &entrada);
    if(entrada%2){
        impar[qtnImpar]=entrada;
        preencherArray(contador-1, qtnImpar+1, qtnPar, impar, par);
    }else{
        par[qtnPar]=entrada;
        preencherArray(contador-1, qtnImpar, qtnPar+1, impar, par);
    }
}

int main(){
    int impar[5], par[5];
    preencherArray(15, 0, 0, impar, par);
    return 0;
}