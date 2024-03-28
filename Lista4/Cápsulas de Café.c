#include <stdio.h>
int laco(int repeticao, int total){
    int qtnCaixas;
    char tamanho;
    if(repeticao--){
        scanf("%d %c", &qtnCaixas, &tamanho);
        if(tamanho=='p' || tamanho=='P'){
            total+=qtnCaixas*10;
        }else{
            total+=qtnCaixas*16;
        }
        return laco(repeticao,total);
    }
    return total;
}
int main() {
    int totalXicaras=laco(7,0);
    printf("%d\n%d",totalXicaras,(totalXicaras/7)*2);
	return 0;
}