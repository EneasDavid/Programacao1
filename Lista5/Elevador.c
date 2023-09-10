#include <stdio.h>
int myWhile(int numeroLeituras, int capacidadeElevador, int loop, int pessoasDentro){
    if (numeroLeituras>loop){
        int entrada, saida;
        scanf("%d%d", &saida, &entrada);
        pessoasDentro+=entrada-saida;
        if((capacidadeElevador-pessoasDentro)>=0){
            return myWhile(numeroLeituras, capacidadeElevador, loop+1, pessoasDentro);
        }
        return 1+myWhile(numeroLeituras, capacidadeElevador, loop+1,pessoasDentro);
    }
    return 0;   
}
int main(){
    int capacidade, leituras;
    scanf("%d%d",&leituras, &capacidade);
    if(myWhile(leituras, capacidade,0,0)>0){
        printf("S\n");
    }else{
        printf("N\n");
    }
    return 0;
}