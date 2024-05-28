#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int campo[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &campo[i][j]);
        }
    }

    int tamanhoDavince = 0, tamanhoAlmoxarifado = 0, tamanhoLaika = 0, tamanhoMirabel = 0;

  //Davince ACIMA
  //Almoxarifado ESQUERDA
  //Laika BAIXO
  //Mirabel DIREITA

    // Imprime os tamanhos máximos do triângulo para cada descendente
    printf("Davince: %d\n", tamanhoDavince);
    printf("Almoxarifado: %d\n", tamanhoAlmoxarifado);
    printf("Laika: %d\n", tamanhoLaika);
    printf("Mirabel: %d\n", tamanhoMirabel);

    return 0;
}
