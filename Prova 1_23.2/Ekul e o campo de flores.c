/*
    esta??o do ano
    o clima no momento
    o hor?rio no momento
    quantidade de tempo de sono de Ekul
    
    O valor do clima na equa??o ser? 7 caso o clima esteja ensolarado, 5 caso seja chuvoso e 3 caso seja nublado;



    Uma linha com 2 inteiros, representando o hor?rio e a quantidade de horas de sono

    Uma linha com 2 caracteres, representando a esta??o do ano (I, V, P ou O) e o clima (E, N, C)

    Uma linha com 4 inteiros, atribuindo valores respectivamente ?s esta??es "Inverno", "Ver?o", "Primavera" e "Outono"
*/
int valorEstacao(char estacao, int inverno, int verao, int primavera, int outono){
    switch (estacao)
    {
    case 'I':
        return inverno;
        break;
    case 'P':
        return primavera;
        break;
    case 'V':
        return verao;
        break;
    case 'O':
        return outono;
        break;
    default:
        break;
    }
}

int valorClima(char clima){
    switch (clima)
    {
    case 'E':
        return 7;
        break;
    case 'C':
        return 5;
        break;
    case 'N':
        return 3;
        break;
    default:
        break;
    }
}

#include <stdio.h>
int main(){
    int horario, qtnHoraSono,inverno, verao, primavera, outono;
    char estacao, clima;
    scanf("%d %d  %c %c %d %d %d %d", &horario, &qtnHoraSono, &estacao, &clima, &inverno, &verao, &primavera, &outono);
    //CHANCE = ESTA??O + (HORARIO EM HORAS % CLIMA) * TEMPO DE SONO
    int vEstacao=valorEstacao(estacao,inverno, verao, primavera, outono);
    int disposicao=(qtnHoraSono/2)*19;
    if(disposicao>=70){
        int chance=vEstacao+((horario/60)%valorClima(clima))*qtnHoraSono;
        if(chance>=(vEstacao*3)){
            printf("%d%%, Ekul possui chances de encontrar a flor :)", chance>100?100:chance);
        }else{
            printf("%d%%, Ekul nao possui chances de encontrar a flor :(", chance>100?100:chance);
        }
   }else{
         printf("%d%%, Ekul nao acordou disposto hoje :(", 0);
   }
    return 0;
}