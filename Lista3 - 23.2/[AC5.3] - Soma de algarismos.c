#include <stdio.h>

int soma(int valor){
    if(!valor) return 0;
    return valor%10+soma(valor/10);
}

int main(){
    int entrada;
    scanf("%d", &entrada);
    printf("%d",soma(entrada));
    return 0;
}