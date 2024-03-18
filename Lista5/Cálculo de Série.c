#include <stdio.h>

double repeticao(int n, int i, double soma, double vImpar, double vPar){
    if(n==i-1){
        return soma;
    }
    if(i%2!=0){
        double iDouble=i;
        soma+=(iDouble/vImpar);
        return repeticao(n, i+1, soma, vImpar*2, vPar);
    }
    else{
        soma += (vImpar / vPar);
        return repeticao(n, i+1, soma, vImpar*2, vPar+3);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("S: %.2lf\n", repeticao(n, 1, 0, 1, 3));
    return 0;
}
