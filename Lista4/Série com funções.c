#include <stdio.h>
int fatorial(int numero){
    if(numero>1){
        return numero*fatorial(numero-1);
    }
    return 1;
}
int eh_primo(int numero){
    int rest1 = numero % 2;
    int rest2 = numero % 3;

    if (numero == 2 || numero == 3){
        return numero;
    }else if (rest1 != 0 && rest2 != 0){
        return numero;
    }else if (rest1 == 0 || rest2 == 0){
        numero++;
    }
    return eh_primo(numero);
}
void calc_serie(int repeticao, int variante, double soma){
    double primo=eh_primo(variante);
    if(variante>repeticao){
        printf("\n%.2lf\n", soma);
        return;
    }else{
        soma+=fatorial(variante)/primo;
        if(variante!=1){
            printf(" + ");
        }
        printf("%d!/%0.lf",variante,primo);
    }
    calc_serie(repeticao, variante+1, soma);
}
int main() {
    int entrada;
    scanf("%d", &entrada);
    calc_serie(entrada, 1, 0);
	return 0;
}