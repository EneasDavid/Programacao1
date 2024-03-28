#include <stdio.h>
int main() {
    int ehHomem, temQuarenta;
    scanf("%d%d", &ehHomem, &temQuarenta);
    if(ehHomem==0 && temQuarenta==1){
        printf("1");
    }else{
        printf("0");
    }
	return 0;
}
//se for homem, nunca tera desconto, e se for mulher, s� tera desconto caso tenha menos de 40 anos