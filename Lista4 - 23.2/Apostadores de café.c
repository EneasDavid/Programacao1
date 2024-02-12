#include <stdio.h>

int empate = 0, kcaj = 0, ordep = 0;

int ePrimo(int digito, int valorVariante) {
    if (digito < 2 || (digito % 2 == 0 && digito != 2)) {
        return 0;
    }
    return digito % valorVariante ? 1 : ePrimo(digito, valorVariante + 1);
}

int ehPotenciaDeDois(int n, int pow) {
    if (pow == n) {
        return 1;
    } else if (pow > n) {
        return 0;
    } else {
        return ehPotenciaDeDois(n, pow * 2);
    }
}

void habilidadeOrdep(int *ataque, int *vida) {
    if (*vida > *ataque) {
        int temp = *ataque;
        *ataque = *vida;
        *vida = temp;
    }
}

void habilidadeKcaj(int *ataque, int *vida) {
    if (*vida % 2)
        *ataque += 5;
}

int simularBatalha(int v1, int v2, int d1, int d2, int rodada) {
    if (v1 <= 0 || v2 <= 0) {
        return (v1 <= 0) ? 0 : 1;
    }

    if (ePrimo(rodada, 2)) {
        habilidadeOrdep(&d1, &v1);
        v2 -= d1;
    } else {
        habilidadeOrdep(&d1, &v1);
        v2 -= d1;
    }

    if (ehPotenciaDeDois(rodada, 2)) {
        habilidadeKcaj(&d2, &v2);
        v1 -= d2;
    } else {
        habilidadeKcaj(&d2, &v2);
        v1 -= d2;
    }

    return simularBatalha(v1, v2, d1, d2, rodada + 1);
}

void myFor(int valor){
    if (!valor) return;
    int ataqueOrdep, vidaOrdep, ataqueKcaj, vidaKcaj;
    scanf("%d %d %d %d", &ataqueOrdep, &vidaOrdep, &ataqueKcaj, &vidaKcaj);
    int resultado = simularBatalha(vidaOrdep, vidaKcaj, ataqueOrdep, ataqueKcaj, 1);
    if(resultado==0) kcaj++;
    else if(resultado==1) ordep++;
    else empate++;
    myFor(valor - 1);
}

int main(){
    int entrada;
    scanf("%d", &entrada);
    myFor(entrada);
    if(empate>0 || ordep == kcaj) {
        printf("F coffees\n");
    }else if(ordep>kcaj){
        printf("ordep ganhou %d coffees\n", ordep);
    }else if(kcaj>ordep){
        printf("kcaj ganhou %d coffees\n", kcaj);
    }
    return 0;
}
/*
Exemplos de:
Entrada

2 41 123 34 73 32 213 32 214
Saída

F coffees
Entrada

15
22   426
13   353
23   225
22   88
40   478
11   467
7   381
2   205
23   265
15   466
22   237
37   197
14   250
19   193
11   63
27   288
28   132
10   461
16   293
40   402
7   434
46   344
31   151
35   142
12   414
22   179
20   236
39   124
23   427
42   179

Saída
ordep ganhou 10 coffees

entrada
5
37  160
27   255
12   451
9   359
46   378
48   284
37   278
37   588
5   26
1   308

Saída
kcaj ganhou 3 coffees

entrada

Saída
kcaj ganhou 2 coffees
*/