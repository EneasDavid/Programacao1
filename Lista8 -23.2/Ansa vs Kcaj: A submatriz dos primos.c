#include <stdio.h>
#include <math.h>
void lerMatriz(int altura, int largura, int matriz[altura][largura]){
    for(int i=0;i<altura;i++){
        for(int d=0;d<largura;d++){
            scanf("%d", &matriz[i][d]);
        }
    }
    return;
}
int ehPrimo(int digito, int raiz) {
    if(digito==1) return 1;
    if(digito<2) return 0;
    if(raiz<2) return 1; 
    return !(digito%raiz)?0:ehPrimo(digito, raiz-1);
}
int escolhendoMatriz(int altura, int largura, int matrix[altura][largura]) {
    int soma=0;
    int melhorMatriz[altura-1][largura-1];
    for(int i=0; i<2;i++) {
        for (int d=0;d<2; d++) {
            int submatriz[altura-1][largura-1];
            int sum=0;
            for (int x=0; x<altura-1; x++) {
                for (int y=0; y<largura-1; y++) {
                    submatriz[x][y]=matrix[i + x][d + y];
                    if (x==y && ehPrimo(submatriz[x][y], sqrt(submatriz[x][y]))) {
                        sum += submatriz[x][y];
                    }
                }
            }
            if (sum>soma) {
                soma=sum;
                for (int x=0; x<altura-1; x++) {
                    for (int y=0; y<largura-1; y++) {
                        melhorMatriz[x][y]=submatriz[x][y];
                    }
                }
            }
        }
    }
    int i, d;
    for (i=0; i<altura-1; i++) {
        for (d=0; d<largura-2; d++) {
            printf("%d ", melhorMatriz[i][d]);
        }
        printf("%d\n", melhorMatriz[i][d]);
    }
    printf("\n");
    return soma;
}
int main() {
    int altura, largura;
    scanf("%d%d", &altura, &largura);
    int matrizJack[altura][largura], matrizAna[altura][largura];
    lerMatriz(altura, largura, matrizJack);
    lerMatriz(altura, largura, matrizAna);
    int pontosJ=escolhendoMatriz(altura, largura, matrizJack);
    int pontosA=escolhendoMatriz(altura, largura, matrizAna);    
    if(pontosJ==pontosA) printf("Empate\n");
    else if(pontosA>pontosJ) printf("Ansa ganhou\n"); 
    else printf("Kcaj ganhou\n");
    return 0;
}