#include <stdio.h>
#include <math.h>

int maiorNumero(int num, int posicao, int maior){
    if(posicao==3) return maior;
    int novoNumero=(num/(int)pow(10, posicao+1))*(int)pow(10, posicao)+num%(int)pow(10, posicao);
    if(novoNumero>maior) maior=novoNumero;
    return maiorNumero(num, posicao+1, maior);
}

void myFor(int casos){
    if(!casos) return;
    int numero;
    scanf("%d", &numero);
    int resultado=maiorNumero(numero, 0, 0);
    printf("%d\n", resultado);
    myFor(casos-1);
}

int main(){
    int casos;
    scanf("%d", &casos);
    myFor(casos);
    return 0;
}
