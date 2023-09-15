#include <stdio.h>

int osvaldo(int x, int tamanho, int v[]) {
    if (x == tamanho) {
        return 0;
    }
    
    int contagem = (v[x] != x) ? 1 : 0;

    return contagem + osvaldo(x + 1, tamanho, v);
}

void looping(int v[], int ind, int tamanho) {
    if (ind == tamanho) {
        return;
    }
    scanf("%d", &v[ind]);
    looping(v, ind + 1, tamanho);
}

int main() {
    int n;
    scanf("%d", &n);
    int v[n];
    looping(v, 0, n);
    printf("%d", osvaldo(0, n, v));
    return 0;
}
