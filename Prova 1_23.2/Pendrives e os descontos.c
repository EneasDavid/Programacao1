#include <stdio.h>

int main(){
    int qtnPendrive;
    scanf("%d", &qtnPendrive);
    if(qtnPendrive>100){
        printf("Poxa, nao temos mais pendrives no estoque");
    }else{
        double valorFinal;
        if(qtnPendrive>6 && qtnPendrive<10){
            valorFinal=(qtnPendrive*5)*.95;
        }else if(qtnPendrive>10){
            valorFinal=(qtnPendrive*5)*.9;
        }else{
            valorFinal=qtnPendrive*5;
        }
        printf("Ainda existe estoque! O valor total eh de R$ %.2lf e sobraram %d pendrives no estoque", valorFinal, (100-qtnPendrive));
    }
    return 0;
}