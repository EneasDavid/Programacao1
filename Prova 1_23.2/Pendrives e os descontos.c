/*
Estoque inicial é de 100 pendrives

Se o cliente comprar até 5 pendrives, não há desconto.
Se o cliente comprar de 6 a 10 pendrives, recebe um desconto de 5% no valor total da compra.
Se o cliente comprar mais de 10 pendrives, recebe um desconto de 10% no valor total da compra.

cada pendrive custa 5 reais.
*/

#include <stdio.h>

int main(){
    int qtnPendrive;
    scanf("%d", &qtnPendrive);
    if(qtnPendrive<=100){
         double valorFinal;
        if(qtnPendrive>6 && qtnPendrive<10){
            valorFinal=(qtnPendrive*5)*.95;
        }else if(qtnPendrive>10){
            valorFinal=(qtnPendrive*5)*.9;
        }else{
            valorFinal=qtnPendrive*5;
        }
        printf("Ainda existe estoque! O valor total eh de R$ %.2lf e sobraram %d pendrives no estoque", valorFinal, (100-qtnPendrive));
    }else{
        printf("Poxa, nao temos mais pendrives no estoque");
    }
    return 0;
}