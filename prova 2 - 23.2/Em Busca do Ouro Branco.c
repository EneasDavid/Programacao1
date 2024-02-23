#include <stdio.h>

void distanciaPortao(int posicao, int esquerda, int direita, int achouE, int achouD, int pasos, int cont){
    printf("%d %d %d %d %d %d %d\n", posicao, cont, pasos, esquerda, direita,cont-esquerda==posicao, cont-direita==posicao, achouE, achouD);
    if(!achouD || !achouE){
        if(cont%2){
            //direita
            pasos+=cont;
            if(cont-esquerda==posicao) achouD=pasos;
            distanciaPortao(posicao, esquerda, cont, achouE, pasos, pasos, cont+1);
        }else{
            //esquerda
            pasos+=cont;
            if(cont-direita==posicao) achouE=pasos;
            distanciaPortao(posicao, cont, direita, pasos, achouD, pasos, cont+1);
        }  
    }else{
        printf("%d %d\n", achouE, achouD);
        return ;
    }
}

void myWhile(){
    int entrada=0;
    scanf("%d", &entrada);
    if(!entrada) return;
    distanciaPortao(entrada, 0, 0, 0, 0, 0, 1);
    myWhile();
    return ;
}

int main(){
    myWhile();
    return 0;
}

/*
distanciaPortao(int posicao, int esquerda, int direita, int achouE, int achouD, int pasos, int cont){
    if(!achouD && !achouE){
        if(cont%2){
            pasos+=cont;
            if(esquerda-cont==posicao) achouD=pasos;
            return (posicaao, esquerda, cont, achouE, achouD, pasos, cont+1)
        }else{
            pasos+=cont;
            if(direita-cont==posicao) achouE=pasos;
            return (posicaao, cont, direita, achouE, achouD, pasos, cont+1);
        }
            
    }
}
if(impar) direita+=cont
else esquerda+=cont
pasos=esquerda+direita
cont=1
[][][][][][][][][2][][*][][2]
1 - 
direita=1
pasos+=direita
[][][][][][][][][2][][0][*][2]
2- 
esquerda=2
pasos+=esquerda
[][][][][][][][][2][*][0][][2]
3 - ok pra direita
direita=3
pasos+=direita
if(direita-esquerda==posicao) achouD=pasos;
[][][][][][][][][2][][0][][*]
4- 
direita=1
pasos+=direita
[][][][][][][][][2][*][0][][]
5- 
direita=1
pasos+=direita
[][][][][][][][][2][*][0][][][]
6- 
direita=1
pasos+=direita
[][][][][][][][][2][][0][][][][*]
7 - ok pra esquerda
direita=1
pasos+=direita
[][][][][][][][][*][][0][][][][]
*/