#include <stdio.h>
#include <math.h>

typedef struct jogador{
    int vida;
    int ataque;
    int vitoria;
}Jogador;

int ehPrimo(int digito, int valorVariante) {
    if(digito<2) return 0;
    if(valorVariante<2) return 1; 
    return !(digito%valorVariante)?0:ehPrimo(digito, valorVariante-1);
}

int ehPotencia(int valor){
    if(valor==1) return 1;
    return !(valor%2)?ehPotencia(valor>>1):0;
}

int ehImpar(int valor){
    return valor%2;
}

void habPedro(Jogador *pedro){
    if(pedro->vida>pedro->ataque){
        pedro->vida=pedro->vida^pedro->ataque;
        pedro->ataque=pedro->vida^pedro->ataque;
        pedro->vida=pedro->vida^pedro->ataque;
    }
}

void habjack(Jogador *jack){
    if(ehImpar(jack->vida)) jack->ataque+=5;
}

void preencheStruct(Jogador *jogadorCadastro, int vida, int ataque, int vitoria){
    jogadorCadastro->vida=vida;
    jogadorCadastro->ataque=ataque;
    jogadorCadastro->vitoria=vitoria;
}

int verificaVitoria(Jogador *ataquente, Jogador *atacado){
     if(atacado->vida<=0){
        ataquente->vitoria+=1;
        return 1;
     }  
     else return 0;
}

void simulacaoBatalha(Jogador *pedro, Jogador *jack, int rodada){
    //printf("Rodada %d\nVida de Pedro: %d Ataque de Pedro: %d\nVida de Jack: %d Ataque de Jack: %d\n",rodada,pedro->vida, pedro->ataque, jack->vida, jack->ataque);
    if(!ehPotencia(rodada)){
        habPedro(pedro);
        jack->vida-=pedro->ataque;
        if(verificaVitoria(pedro, jack)) return; 
    }
    if(!ehPrimo(rodada, sqrt(rodada))){
        habjack(jack);
        pedro->vida-=jack->ataque;
        if(verificaVitoria(jack, pedro)) return; 
    }
    simulacaoBatalha(pedro, jack, rodada+1);
}

void myWhile(int contador, Jogador *pedro, Jogador *jack){
    if(!contador) return;
    int vidaP, ataqueP, vidaJ, ataqueJ;
    scanf("%d%d%d%d", &ataqueP, &vidaP, &ataqueJ, &vidaJ);
    preencheStruct(pedro, vidaP, ataqueP, pedro->vitoria);
    preencheStruct(jack, vidaJ, ataqueJ, jack->vitoria);
    simulacaoBatalha(pedro, jack, 1);
    myWhile(contador-1, pedro, jack);
}

int main(){
    int entrada;
    Jogador Pedro, Jack;
    Pedro.vitoria=0;
    Jack.vitoria=0;
    scanf("%d", &entrada);
    myWhile(entrada, &Pedro, &Jack);
    if(Pedro.vitoria==Jack.vitoria) printf("F coffees");
    else if(Pedro.vitoria>Jack.vitoria) printf("ordep ganhou %d coffees", Pedro.vitoria);
    else if(Jack.vitoria>Pedro.vitoria) printf("kcaj ganhou %d coffees", Jack.vitoria);
    return 0;
}