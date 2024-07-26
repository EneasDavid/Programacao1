//Adendo, creio que não possa usar nem ponteiro e nem struct, então antes de só submeter, verifique as tecnologias usadas

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int classe;
    double ataque;
    double vida;
    int vitoria;
} Carta;

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

void determinarVencedor(Carta *cartaUm, Carta *cartaDois) {
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
    if (cartaUm->vida <= 0) cartaDois->vitoria++;
    else if (cartaDois->vida <= 0) cartaUm->vitoria++;
    else {
        //Em casos em que nenhuma carta foi eliminada, o vencedor é aquele com mais pontos de vida
        if(cartaUm->vida>cartaDois->vida) cartaUm->vitoria++;
        else if(cartaUm->vida<cartaDois->vida) cartaDois->vitoria++;
        else{
            //Caso ainda tenha empates, o vencedor será aquele com maior pontos de ataque.
            if (cartaUm->ataque > cartaDois->ataque) cartaUm->vitoria++;
            else if (cartaUm->ataque < cartaDois->ataque) cartaDois->vitoria++;
        }
    }
}

void recebeCarta(Carta *carta) {
    scanf("%d %lf %lf", &carta->classe, &carta->ataque, &carta->vida);
}

int soma(Carta carta, Carta cartaDois, Carta cartaTres) {
    return carta.vitoria+cartaDois.vitoria+cartaTres.vitoria;
}

int main() {
    Carta cartaPedroUm, cartaPedroDois, cartaPedroTres;
    Carta cartaTulioUm, cartaTulioDois, cartaTulioTres;

    recebeCarta(&cartaPedroUm);
    recebeCarta(&cartaPedroDois);
    recebeCarta(&cartaPedroTres);
    
    recebeCarta(&cartaTulioUm);
    recebeCarta(&cartaTulioDois);
    recebeCarta(&cartaTulioTres);
    
    calcularBonus(&cartaPedroUm, &cartaTulioUm);
    calcularBonus(&cartaPedroDois, &cartaTulioDois);
    calcularBonus(&cartaPedroTres, &cartaTulioTres);

    determinarVencedor(&cartaPedroUm, &cartaTulioUm);   
    determinarVencedor(&cartaPedroDois, &cartaTulioDois);
    determinarVencedor(&cartaPedroTres, &cartaTulioTres);

    printf("Rodada1: %s\n", cartaPedroUm.vitoria>cartaTulioUm.vitoria?"Pedro":cartaPedroUm.vitoria<cartaTulioUm.vitoria?"Tulio":"Empate");
    printf("Rodada2: %s\n", cartaPedroDois.vitoria>cartaTulioDois.vitoria?"Pedro":cartaPedroDois.vitoria<cartaTulioDois.vitoria?"Tulio":"Empate");
    printf("Rodada3: %s\n", cartaPedroTres.vitoria>cartaTulioTres.vitoria?"Pedro":cartaPedroTres.vitoria<cartaTulioTres.vitoria?"Tulio":"Empate");

    if (soma(cartaPedroUm, cartaPedroDois, cartaPedroTres) > soma(cartaTulioUm, cartaTulioDois, cartaTulioTres)) printf("Pedro vitorioso\n");
    else if (soma(cartaPedroUm, cartaPedroDois, cartaPedroTres) < soma(cartaTulioUm, cartaTulioDois, cartaTulioTres)) printf("Tulio vitorioso\n");
    else printf("Empate\n");

    return 0;
}