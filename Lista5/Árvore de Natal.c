#include <stdio.h>

double my_while(int laco, double total){
    double qtn, pItem;
    if(laco>0){
        scanf("%lf%lf", &qtn,&pItem);
        return my_while(laco-1,total+(qtn*pItem));
    }
    return total;
}
int main() {
    double precoArvore;
    scanf("%lf", &precoArvore);
    double saida=precoArvore+my_while(3,0);
    printf("%.2lf\n%.2lf", saida, saida/21);
	return 0;
}