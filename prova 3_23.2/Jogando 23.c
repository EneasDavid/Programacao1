#include <stdio.h>

int achaMelhorCarta(int faltaBea, int faltaHugo, int cartasOut[], int contador) {
    if(faltaBea>10) return -1;
    if(faltaBea-contador==0 || faltaHugo-contador<0){
        if(contador>9 && contador<14) {
            int verifica;
            if (cartasOut[10]<4) verifica=10;
            else if (cartasOut[11]<4) verifica=11;
            else if (cartasOut[12]<4) verifica=12;
            else if (cartasOut[13]<4) verifica=13;
            return faltaBea-verifica>=0?verifica:-1;
        }
        if(cartasOut[contador-1]<4) return faltaBea-contador>=0?contador:-1;
    }
    achaMelhorCarta(faltaBea, faltaHugo, cartasOut, contador+1);
}

int somaCartas(int array[], int contador){
    if(contador<0) return 0;
    return array[contador]+somaCartas(array, contador-1);
}

void myFor(int array[], int cont, int outDeek[]) {
    if (cont<0) return;
    myFor(array, cont-1, outDeek);
    int valor;
    scanf("%d", &valor);
   // printf("%d ", valor);
    outDeek[valor-1]+=1;
    //printf("%d\n", outDeek[valor-1]);
    if(valor>10 && valor<14) valor = 10;
    array[cont] = valor;
}

int main() {
    int qtnJogadas, cartasOut[13] = {0};
    scanf("%d", &qtnJogadas);
    int cartaINicialHugo[2], cartaInicialBea[2], cartasComuns[qtnJogadas];
    myFor(cartaINicialHugo, 1, cartasOut);
    myFor(cartaInicialBea, 1, cartasOut);
    myFor(cartasComuns, qtnJogadas - 1, cartasOut);
    int pontosC=somaCartas(cartasComuns,qtnJogadas-1);
    int pontosH=somaCartas(cartaINicialHugo,1)+pontosC;
    int pontosB=somaCartas(cartaInicialBea,1)+pontosC;
    /*    
    printf("cartas hugo: %d\n", pontosH);
    printf("cartas bea: %d\n", pontosB);
    printf("cartas comum: %d\n", pontosC);
    */
    int faltaBea=23-pontosB;
    int faltaHugo=23-pontosH;
    printf("%d\n", achaMelhorCarta(faltaBea, faltaHugo, cartasOut, 1));

    /*
    for (int i = 0; i < 2; i++) {
        printf("cartas hugo: %d\n", cartaINicialHugo[i]);
    }
    for (int i = 0; i < 2; i++) {
        printf("cartas bea: %d\n", cartaInicialBea[i]);
    }
    for (int i = 0; i < qtnJogadas; i++) {
        printf("cartas comuns: %d\n", cartasComuns[i]);
    }
    printf("%d\n", cartasOut[0]);
    for (int i = 0; i < 13; i++) {
        printf("cartas %d %s", i + 1, cartasOut[i] == 4 ? "fora\n" : "\n");
    }
    */
    return 0;
}