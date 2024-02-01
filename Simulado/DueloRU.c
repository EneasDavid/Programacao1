#include <stdio.h>
/*
int rodada(cartaPedro, cartaTulio){
    if(carta){

    }
}
    dicionarioCalse = [
        {1, "Guerreiro"},
        {2, "Mago"},
        {3, "Arqueiro"},
    ];
*/

typedef struct {
    int classe;
    double ataque;
    double vida;
} Carta;

Carta recebeCarta() {
    Carta carta;
    scanf("%d %2.lf %2.lf", &carta.classe, &carta.ataque, &carta.vida);
    return carta;
}

int main() {

    Carta cartaPedroUm, cartaPedroDois, cartaPedroTres;
    Carta cartaTulioUm, cartaTulioDois, cartaTulioTres;

    cartaPedroUm=recebeCarta();
    cartaPedroDois=recebeCarta();
    cartaPedroTres=recebeCarta();

    cartaTulioUm=recebeCarta();
    cartaTulioDois=recebeCarta();
    cartaTulioTres=recebeCarta();
    return 0;
}
