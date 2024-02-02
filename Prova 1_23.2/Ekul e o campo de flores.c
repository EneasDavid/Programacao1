#include <stdio.h>

int main(){
    int horario, qtnHoraSono,inverno, verao, primavera, outono;
    char estacao, clima;
    scanf("%d %d %c %c %d %d %d %d", &horario, &qtnHoraSono, &estacao, &clima, &inverno, &verao, &primavera, &outono);
    //CHANCE = ESTA??O + (HORARIO EM HORAS % CLIMA) * TEMPO DE SONO
    int vEstacao=estacao=='I'?inverno:estacao=='V'?verao:estacao=='P'?primavera:outono;
    int vClima=clima=='E'?7:clima=='C'?5:3;
    int disposicao=(qtnHoraSono/2)*19;
    if(disposicao>=70){
        int chance=vEstacao+((horario/60)%vClima)*qtnHoraSono;
        if(chance>=(vEstacao*3) || chance>100){
            printf("%d%%, Ekul possui chances de encontrar a flor :)", chance>100?100:chance);
        }else{
            printf("%d%%, Ekul nao possui chances de encontrar a flor :(", chance);
        }
   }else{
         printf("0%%, Ekul nao acordou disposto hoje :(");
   }
    return 0;
}