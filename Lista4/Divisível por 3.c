#include <stdio.h>
eDivTres(int dividendo, int divisor){
    if(divisor>2){
        if(divisor%3==0 && dividendo%divisor==0){
            return 1+eDivTres(dividendo, divisor-1);
        }
        return eDivTres(dividendo, divisor-1);
    }
    return 0;
}
int main() {
    int n;
    scanf("%d", &n);
    int qtnDivisores=eDivTres(n,n);
    if(qtnDivisores>0){
       printf("%d",qtnDivisores); 
    }else{
        printf("O numero nao possui divisores multiplos de 3!");
    }
	return 0;
}