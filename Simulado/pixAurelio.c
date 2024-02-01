#include <stdio.h>

// Function mostrar valor da letra de acordo com a escolha da pessoa
int escolhendoLetra(int valorA, int valorB, int valorC, int valorD, char escolhaPessoa) {
    switch (escolhaPessoa) {
        case 'a':
            return valorA;
        case 'b':
            return valorB;
        case 'c':
            return valorC;
        case 'd':
            return valorD;
        default:
            return 0;
    }
}

// Function calcular pontos de cada pessoa numPessoa+escolhaPessoa+(escolhaPessoa*fator)
double calculaPontos(int escolhaPessoa, int numPessoa, double fator) {
    return numPessoa+escolhaPessoa+(escolhaPessoa*fator);
}

int main() {
    // Input values
    int numAnderson, numGuilherme, numRita, numHigor;
    int valorA, valorB, valorC, valorD;
    char escolhaAnderson, escolhaGuilherme, escolhaRita, escolhaHigor;

    scanf("%d%d%d%d %c %c %c %c %d%d%d%d",
          &numAnderson, &numGuilherme, &numRita, &numHigor,
          &escolhaAnderson, &escolhaGuilherme, &escolhaRita, &escolhaHigor,
          &valorA, &valorB, &valorC, &valorD);

    // mostrar o valor das letras escolhidas com a fanção
    int letraAnderson = escolhendoLetra(valorA, valorB, valorC, valorD, escolhaAnderson);
    int letraGuilherme = escolhendoLetra(valorA, valorB, valorC, valorD, escolhaGuilherme);
    int letraRita = escolhendoLetra(valorA, valorB, valorC, valorD, escolhaRita);
    int letraHigor = escolhendoLetra(valorA, valorB, valorC, valorD, escolhaHigor);

    // calcular a media
    int media = (numAnderson + numGuilherme + numRita + numHigor) / 4;

    // Definir o fator de acordo com a media
    double fator = (media >= 0 && media <= 10) ? 0.4 : (media > 10 && media <= 30) ? 0.6 : (media > 30 && media <= 60) ? 0.8 : 1;

    // Ccalcular os pontos com a função de calcular pontos
    double pontosAnderson = calculaPontos(letraAnderson, numAnderson, fator);
    double pontosGuilherme = calculaPontos(letraGuilherme, numGuilherme, fator);
    double pontosRita = calculaPontos(letraRita, numRita, fator);
    double pontosHigor = calculaPontos(letraHigor, numHigor, fator);

    // Encontre o perder com os pontos calculados
    int perdedor = 0;
    double menorvalor = pontosAnderson;
    if (pontosGuilherme < menorvalor) {
        menorvalor = pontosGuilherme;
        perdedor = 1;
    }if (pontosRita < menorvalor) {
        menorvalor = pontosRita;
        perdedor = 2;
    }if (pontosHigor < menorvalor) {
        menorvalor = pontosHigor;
        perdedor = 3;
    }

    // mostre o resultado usando o perdedor descoberto anteriormente
    if (perdedor == 0) {
        printf("Anderson quem vai pagar o lanche!:D\n");
    } else if (perdedor == 1) {
        printf("Guilherme quem vai pagar o lanche!:D\n");
    } else if (perdedor == 2) {
        printf("Rita quem vai pagar o lanche!:D\n");
    } else if (perdedor == 3) {
        printf("Higor quem vai pagar o lanche!:D\n");
    }

    return 0;
}

/*
anderson = 50. 100
guilherme = 40. 70
rita = 60. 20
higor = 30. 50

fator = 0.8
valorA = 50+100+(100*0.8) = 190
valorG = 40+70+(70*0.8) = 138
valorR = 60+20+(20*0.8) = 128
valorH = 30+50+(50*0.8) = 104
50 40 60 30
b c d a
50 100 70 20

*/