#include <stdio.h>
#include <string.h>

int somatarioDigitos(int entrada, int soma){

    if(entrada>0){
        soma+=entrada%10;
        return somatarioDigitos(entrada/10,soma);
    }
    
    return soma;
}

void entrada(int vezes, int empate, int pontuacaoPedro, int pontuacaoAnderson, int pontuacaoHugo){
    int jogadaPedro, jogadaAnderson, jogadaHugo, valor;    
    if(vezes==0){
        char quemganhou [10] = "Pedro";
        if(pontuacaoPedro<=pontuacaoAnderson){
             strcpy(quemganhou, "Anderson");
        }
        if(pontuacaoAnderson<=pontuacaoHugo){
             strcpy(quemganhou, "Hugo");
        }
        printf("Pontuacao Pedro: %d\nPontuacao Anderson: %d\nPontuacao Hugo: %d\nEmpates: %d\n%s ganhou",pontuacaoPedro,pontuacaoAnderson,pontuacaoHugo,empate,quemganhou);
 
    }else{
        scanf("%d%d%d", &jogadaPedro, &jogadaAnderson, &jogadaHugo);
        if((jogadaPedro+jogadaAnderson+jogadaHugo)%2>0){
            valor=(jogadaPedro*jogadaAnderson*jogadaHugo)/2;
        }else{
            valor=somatarioDigitos(jogadaPedro,0)*somatarioDigitos(jogadaAnderson,0)*somatarioDigitos(jogadaHugo,0);
        }
        if((valor%10)==0){
            empate++;
        }else if((valor%10)<=3){
            pontuacaoPedro+=valor;
        }else if((valor%10)<=6){
            pontuacaoAnderson+=valor;
        }else if((valor%10)<=9){
            pontuacaoHugo+=valor;
        }
        entrada(vezes-1,empate, pontuacaoPedro, pontuacaoAnderson, pontuacaoHugo);   
    }

}

int main() {
    int vezesJogada;
    scanf("%d", &vezesJogada);
    entrada(vezesJogada,0,0,0,0);
	return 0;
}
