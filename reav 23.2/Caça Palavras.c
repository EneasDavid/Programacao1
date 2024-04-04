#include <stdio.h>
#include <string.h>

int main() {
    int tamanhoCacaPalavra, qtdPalavra, cont = 0;
    scanf("%d", &tamanhoCacaPalavra);
    char cacaPalavra[tamanhoCacaPalavra][tamanhoCacaPalavra];

    // Entrada das palavras da matriz
    for(int i = 0; i < tamanhoCacaPalavra; i++) {
        scanf("%s", cacaPalavra[i]);
    }

    scanf("%d", &qtdPalavra);
    char palavras[qtdPalavra][tamanhoCacaPalavra];

    // Entrada das palavras a serem buscadas
    for(int i = 0; i < qtdPalavra; i++) {
        scanf("%s", palavras[i]);
    }

    // Busca das palavras
    for(int i = 0; i < qtdPalavra; i++) {
        int tamanhoP = strlen(palavras[i]);
        for(int d = 0; d < tamanhoCacaPalavra; d++) {
            for(int j = 0; j < tamanhoCacaPalavra; j++) {
                // Procura vertical
                if(strstr(cacaPalavra[d] + j, palavras[i]) == cacaPalavra[d] + j) {
                    cont++;
                }
                // Procura horizontal
                if(strstr(cacaPalavra[j] + d, palavras[i]) == cacaPalavra[j] + d) {
                    cont++;
                }
            }
        }
    }

    printf("%d\n", cont);
    return 0;
}
