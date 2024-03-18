#include <stdio.h> 
int suaFuncao(int entrada, int valorDeDviisao){
    if(!entrada%valorDeDviisao) return valorDeDviisao;
    return suaFuncao(entrada/valorDeDviisao, valorDeDviisao+1);
}
int main(){
    int entrada;
    scanf("%d", &entrada);
    printf("%d *",suaFuncao(entrada, 2));
    return 0;
}
