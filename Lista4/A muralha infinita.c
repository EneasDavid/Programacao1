#include <stdio.h>
int moedas(int vezes, int direita, int cima, int local){
        if(vezes--){
             if(direita<cima){
                 local=1;
             }else if(direita>cima){
                 local=2;
             }
            char posicao;
            scanf(" %c", &posicao);
            if(direita==cima){
                 if(posicao=='C'){
                     if(local==2){
                         return 1+moedas(vezes, direita, cima+1, local);
                     }
                 }else if(posicao=='D'){
                     if(local==1){
                         return 1+moedas(vezes, direita+1, cima, local);                
                     }
                }
            }
            if(posicao=='C'){
                return moedas(vezes, direita, cima+1, local);
            }else if(posicao=='D'){
                return moedas(vezes, direita+1, cima, local);                
            }
        }
    return 0;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", moedas(n,0,0,0));
    return 0;
}