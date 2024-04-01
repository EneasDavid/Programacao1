#include <stdio.h>
void ler(int matriz[5][5]){
    for(int i=0; i<5; i++){
        for(int d=0; d<5; d++){
            scanf("%d", &matriz[i][d]);
        }
    }
}
int main(){
    int qtnDuelos;
    scanf("%d", &qtnDuelos);
    while(qtnDuelos--){
        int matrizUm[5][5]; int matrizDois[5][5];
        char jogadorUm[100], jogadorDois[100];
        scanf("%s", jogadorUm);
        ler(matrizUm);
        scanf("%s", jogadorDois);
        ler(matrizDois);
        int somaDiagonalUm=0; int somaDiagonalDois=0;
        for(int i=0;i<5;i++){
            for(int d=0;d<5;d++){
                if(i==d){
                    somaDiagonalUm+=matrizUm[i][d];
                    somaDiagonalDois+=matrizDois[i][d];
                }
                if(i+d==4){
                    somaDiagonalUm+=matrizUm[i][d];
                    somaDiagonalDois+=matrizDois[i][d];
                }
            }
        }
        if(somaDiagonalUm==somaDiagonalDois) printf("Empataram com o valor %d\n", somaDiagonalUm);
        else if(somaDiagonalUm>somaDiagonalDois) printf("%s venceu com valor %d\n", jogadorUm,  somaDiagonalUm);
        else printf("%s venceu com valor %d\n", jogadorDois, somaDiagonalDois);
        /*
        [00][01][02][03]
        [10][11][12][13]
        [20][21][22][23]
        [30][31][32][33]
        DiagonalPrincipal=i==d;
        DiagonalSecundaria=i+d==tamanhoMatriz;
        */

    }
    return 0;
}