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

    for (int princesa=0; princesa<qtdPrincesas; princesa++) {
        int cont=0;
        for (int eleitor=0; eleitor<qtdEleitores; eleitor++) {
            cont+=votos[eleitor][princesa];
        }
        printf("Princesa %d: %d voto(s)\n", princesa+1, cont);
    }
    return 0;
}