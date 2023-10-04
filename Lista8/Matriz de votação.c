#include <stdio.h>

int main() {
    int qtdPrincesas, qtdEleitores;
    scanf("%d", &qtdPrincesas);
    scanf("%d", &qtdEleitores);
    int votos[qtdEleitores][qtdPrincesas];
    for (int linha=0; linha<qtdEleitores; linha++) {
        for (int coluna=0; coluna<qtdPrincesas; coluna++) {
            scanf("%d", &votos[linha][coluna]);
        }
    }
    int transposta[qtdPrincesas][qtdEleitores];
    for (int linha=0; linha<qtdPrincesas; linha++) {
        for (int coluna=0; coluna<qtdEleitores; coluna++) {
            transposta[linha][coluna] = votos[coluna][linha];
        }
    }
    for (int linha=0; linha<qtdPrincesas; linha++) {
        int cont=0;
        for (int coluna=0; coluna<qtdEleitores; coluna++) {
            cont+=transposta[linha][coluna];
        }
        printf("Princesa %d: %d voto(s)\n", linha+1, cont);
    }
    return 0;
}
