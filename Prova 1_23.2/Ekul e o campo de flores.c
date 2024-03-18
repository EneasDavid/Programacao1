#include <stdio.h>
int main(){
    int horario, qtnHoraSono,inverno, verao, primavera, outono, disposicao;
    char estacao, clima;
    scanf("%d %d %c %c %d %d %d %d", &horario, &qtnHoraSono, &estacao, &clima, &inverno, &verao, &primavera, &outono);
    disposicao=qtnHoraSono*9.5;
    if(disposicao<70){
        printf("0%%, Ekul nao acordou disposto hoje :(");
    }else{
        int vEstacao=estacao=='I'?inverno:estacao=='V'?verao:estacao=='P'?primavera:outono;
        int vClima=clima=='E'?7:clima=='C'?5:3;
        int chance=(vEstacao+((horario/60)%vClima)*qtnHoraSono);
        chance=chance>100?100:chance;
        vEstacao=vEstacao*3>100?100:vEstacao;
        if(chance>=vEstacao){
            printf("%d%%, Ekul possui chances de encontrar a flor :)", chance);
        }else{
            printf("%d%%, Ekul nao possui chances de encontrar a flor :(", chance);
        }
    }
    return 0;
}