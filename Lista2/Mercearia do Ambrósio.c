#include <stdio.h>
void vF(int quant, double pProd){
    if(quant>=15 || pProd>=40){
        printf("R$ %.2f",pProd*0.85);
    }else{
        printf("R$ %.2f",pProd);
    }
}
int main() {
    int quant, prod;
    scanf("%d %d", &prod, &quant);
    double preco;
    if(prod==1){
        preco=quant*5.3;
    }else if(prod==2){
        preco=quant*6;
    }else if(prod==3){
      preco=quant*3.2;  
    }else if(prod==4){
       preco=quant*2.5; 
    }
    vF(quant,preco);
	return 0;
}