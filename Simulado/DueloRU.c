//Adendo, creio que não possa usar nem ponteiro e nem struct, então antes de só submeter, verifique as tecnologias usadas

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int classe;
    double ataque;
    double vida;
} Carta;

typedef struct {
    int vitoria[3];
    char nome[MAX];
} Jogador;

void calcularBonus(Carta *carta, Carta *cartaDois) {
   //    Caso 1: Duelo entre Guerreiro(1) e Arqueiro(3). O guerreiro recebe um aumento de 30% em relação a sua vida.
    if (carta->classe == 1 && cartaDois->classe == 3) carta->vida *= 1.3;
    else if (carta->classe == 3 && cartaDois->classe == 1) cartaDois->vida *= 1.3;
    
    //    Caso 2: Duelo entre Arqueiro(3) e Mago(2). O arqueiro recebe um aumento de 25% em relação ao seu ataque.
    else if (carta->classe == 3 && cartaDois->classe == 2) carta->ataque *= 1.25;
    else if (carta->classe == 2 && cartaDois->classe == 3) cartaDois->ataque *= 1.25;
    //    Caso 3: Duelo entre Mago(2) e Guerreiro(1). O mago recebe um aumento de 15% em sua vida e em seu ataque.
    else if (carta->classe == 2 && cartaDois->classe == 1) {
        carta->vida *= 1.15;
        carta->ataque *= 1.15;
    } else if (carta->classe == 1 && cartaDois->classe == 2) {
        cartaDois->vida *= 1.15;
        cartaDois->ataque *= 1.15;
    }
}

void determinarVencedor(Carta *cartaUm, Carta *cartaDois, Jogador *um, Jogador *dois, int rodada) {
    //a carta com menos vida ataca primeiro (Caso sejam iguais, Pedro começa)
    if (cartaUm->vida > cartaDois->vida) {
        cartaUm->vida -= cartaDois->ataque;
        //Se a carta que sofreu o ataque não morrer, ela irá atacar de volta, encerrando o duelo com apenas um ataque de cada
        if (cartaUm->vida > 0) cartaDois->vida -= cartaUm->ataque;

    } else {
        cartaDois->vida -= cartaUm->ataque;
        //Se a carta que sofreu o ataque não morrer, ela irá atacar de volta, encerrando o duelo com apenas um ataque de cada
        if (cartaDois->vida > 0) cartaUm->vida -= cartaDois->ataque;
    }
    //O vencedor do duelo é aquele cuja carta conseguir matar a carta inimiga
    if (cartaUm->vida <= 0) dois->vitoria[rodada]++;
    else if (cartaDois->vida <= 0) um->vitoria[rodada]++;
    else {
        //Em casos em que nenhuma carta foi eliminada, o vencedor é aquele com mais pontos de vida
        if(cartaUm->vida>cartaDois->vida) um->vitoria[rodada]++;
        else if(cartaUm->vida<cartaDois->vida) dois->vitoria[rodada]++;
        else{
            //Caso ainda tenha empates, o vencedor será aquele com maior pontos de ataque.
            if (cartaUm->ataque > cartaDois->ataque) um->vitoria[rodada]++;
            else if (cartaUm->ataque < cartaDois->ataque) dois->vitoria[rodada]++;
        }
    }
}

void recebeCarta(Carta *carta) {
    scanf("%d %lf %lf", &carta->classe, &carta->ataque, &carta->vida);
}

int soma(Jogador jogador) {
    return jogador.vitoria[0] + jogador.vitoria[1] + jogador.vitoria[2];
}

int main() {
    Carta cartaPedroUm, cartaPedroDois, cartaPedroTres;
    Carta cartaTulioUm, cartaTulioDois, cartaTulioTres;

    Jogador pedro = {{0, 0, 0}, "Pedro"};
    Jogador tulio = {{0, 0, 0}, "Tulio"};
    
    recebeCarta(&cartaPedroUm);
    recebeCarta(&cartaPedroDois);
    recebeCarta(&cartaPedroTres);
    
    recebeCarta(&cartaTulioUm);
    recebeCarta(&cartaTulioDois);
    recebeCarta(&cartaTulioTres);
    
    calcularBonus(&cartaPedroUm, &cartaTulioUm);
    calcularBonus(&cartaPedroDois, &cartaTulioDois);
    calcularBonus(&cartaPedroTres, &cartaTulioTres);

    determinarVencedor(&cartaPedroUm, &cartaTulioUm, &pedro, &tulio, 0);   
    determinarVencedor(&cartaPedroDois, &cartaTulioDois, &pedro, &tulio, 1);
    determinarVencedor(&cartaPedroTres, &cartaTulioTres, &pedro, &tulio, 2);

    printf("Rodada1: %s\n", pedro.vitoria[0] > tulio.vitoria[0] ? pedro.nome : (pedro.vitoria[0] < tulio.vitoria[0] ? tulio.nome : "Empate"));
    printf("Rodada2: %s\n", pedro.vitoria[1] > tulio.vitoria[1] ? pedro.nome : (pedro.vitoria[1] < tulio.vitoria[1] ? tulio.nome : "Empate"));
    printf("Rodada3: %s\n", pedro.vitoria[2] > tulio.vitoria[2] ? pedro.nome : (pedro.vitoria[2] < tulio.vitoria[2] ? tulio.nome : "Empate"));

    if (soma(pedro) > soma(tulio)) printf("Pedro vitorioso\n");
    else if (soma(tulio) > soma(pedro)) printf("Tulio vitorioso\n");
    else printf("Empate\n");

    return 0;
}