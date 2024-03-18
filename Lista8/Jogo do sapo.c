#include <stdio.h>

void realizarRodada(int jogadores, int casas, int valorCasa[], int posicao[], int jogador) {
    int dado;
    scanf("%d", &dado);
    int novaPosicao=posicao[jogador] + dado;
    if(novaPosicao>=casas) novaPosicao %= casas;
    novaPosicao+=valorCasa[novaPosicao];
    if(novaPosicao>=casas) novaPosicao%=casas;
    if(novaPosicao<0) novaPosicao=casas+novaPosicao;
    posicao[jogador]=novaPosicao;
}

int main() {
    int casas, jogadores, rodadas;
    scanf("%d %d %d", &casas, &jogadores, &rodadas);
    int valorCasa[casas];
    int posicao[jogadores];
    for (int i=0; i<casas; i++) {
        scanf("%d", &valorCasa[i]);
    }
    for (int i=0; i<jogadores; i++) {
        posicao[i]=0;
    }
    for (int r=0; r<rodadas; r++) {
        for (int jogador=0; jogador<jogadores; jogador++) {
            realizarRodada(jogadores, casas, valorCasa, posicao, jogador);
        }
    }
    for (int i=0; i<jogadores; i++) {
        printf("%d\n", posicao[i]);
    }
    return 0;
}