#include <stdio.h>

int encontreTocas(int arr[], int ind, int tamanho) {
    if (ind==tamanho) {
        if (arr[arr[tamanho-1]]==tamanho-1) {
            return 1;
        } else {
            return 0;
        }
    }
    int contador = (arr[ind]==arr[tamanho-1])?1:0;
    return contador + encontreTocas(arr, ind + 1, tamanho);
}

void myFor(int arr[], int ind, int tamanho) {
    if (ind==tamanho) {
        return;
    }
    scanf("%d", &arr[ind]);
    myFor(arr, ind+1, tamanho);
}

int main() {
    int n;
    scanf("%d", &n);
    int connections[n];
    myFor(connections, 0, n);
    int tocas = encontreTocas(connections, 0, n);
    printf("%d\n", tocas);
    return 0;
}
