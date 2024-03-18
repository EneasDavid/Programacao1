#include <stdio.h>
calc(int n, int variante){
    if(variante<10){
        printf("%d X %d = %d\n", n, variante, n*variante);
        return calc(n,variante+1);
    }
}
int main() {
    int numero;
    scanf("%d", &numero);
    calc(numero, 1);
 	return 0;
}