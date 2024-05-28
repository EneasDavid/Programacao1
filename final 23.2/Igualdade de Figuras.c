#include <stdio.h>

void lerMatriz(int n, int original[n][n]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &original[i][j]);
        }
    }
}

int compara(int n, int matriz1[n][n], int matriz2[n][n]) {
    if (n == 1) return matriz1[0][0] == matriz2[0][0];
    int metade = n/2;
    int submatriz1[metade][metade], submatriz2[metade][metade];
    for (int i = 0; i < metade; i++) {
        for (int j = 0; j < metade; j++) {
            submatriz1[i][j] = matriz1[i][j];
            submatriz2[i][j] = matriz2[i][j];
        }
    }
    return (compara(metade, submatriz1, submatriz2) &&
            compara(metade, &matriz1[metade][0], &matriz2[metade][0]) &&
            compara(metade, &matriz1[0][metade], &matriz2[0][metade]) &&
            compara(metade, &matriz1[metade][metade], &matriz2[metade][metade]));
}

void gira(int n, int matriz[n][n]) {
    int temp;
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            temp = matriz[i][j];
            matriz[i][j] = matriz[n - 1 - j][i];
            matriz[n - 1 - j][i] = matriz[n - 1 - i][n - 1 - j];
            matriz[n - 1 - i][n - 1 - j] = matriz[j][n - 1 - i];
            matriz[j][n - 1 - i] = temp;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int original[n][n];
    lerMatriz(n, original);
    int x;
    scanf("%d", &x);
    int contador = 0;
    for (int k = 0; k < x; k++) {
        int figura[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &figura[i][j]);
            }
        }
        if (compara(n, original, figura)) contador++;
        else {
            for (int r = 0; r < 3; r++) {
                gira(n, figura);
                if (compara(n, original, figura)) {
                    contador++;
                    break;
                }
            }
        }
    }
    printf("O H. Knight achou %d figuras iguais\n", contador);
    return 0;
}
