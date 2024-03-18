#include <stdio.h>

int saoCoprimos(int a, int b){
    while (!b){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a==1;
}

void calcularBonus(int confianca, char estado, int vidaBase, int *bonusVida, int *bonusAtaque){
    if(estado=='F'){
        int a=0, b=1;
        while(b<=confianca){
            if(b==confianca){
                *bonusVida=b%100;
                *bonusAtaque=(*bonusVida)/2;
                return;
            }
            int temp=a+b;
            a=b;
            b=temp;
        }
    } else if(estado=='C' && saoCoprimos(confianca, vidaBase)) {
        *bonusVida=(confianca/10)%10;
        *bonusAtaque=(*bonusVida)/2;
    }
}

int main(){
    int N;
    scanf("%d", &N);

    int vidaBaseEkul, ataqueBaseEkul, vidaBaseLuke, ataqueBaseLuke;
    int bonusVidaEkul, bonusAtaqueEkul;

    for(int i=0; i<N; i++){
        scanf("%d %d %d %d", &vidaBaseEkul, &ataqueBaseEkul, &vidaBaseLuke, &ataqueBaseLuke);
        int M;
        scanf("%d", &M);
        bonusVidaEkul = 0;
        bonusAtaqueEkul = 0;
        for (int j=0; j<M; j++) {
            int confianca;
            char estado;
            scanf("%d %c", &confianca, &estado);

            int bonusVida, bonusAtaque;
            calcularBonus(confianca, estado, vidaBaseEkul, &bonusVida, &bonusAtaque);

            bonusVidaEkul += bonusVida;
            bonusAtaqueEkul += bonusAtaque;
        }

        // Início do duelo
        while (1) {
            // Ekul ataca primeiro
            vidaBaseLuke -= (ataqueBaseEkul + bonusAtaqueEkul);
            if (vidaBaseLuke <= 0) {
                printf("Ekul venceu o round!\nVida restante: %d\n", vidaBaseEkul);
                break;
            }

            // Luke ataca em resposta
            vidaBaseEkul -= (ataqueBaseLuke + bonusAtaqueEkul);
            if (vidaBaseEkul <= 0) {
                printf("Luke venceu o round!\nVida restante: %d\n", vidaBaseLuke);
                break;
            }
        }
    }

    // Verifica o vencedor final do duelo
    if (vidaBaseEkul <= 0) {
        printf("Luke concluiu seu plano maligno!\n");
    } else {
        printf("Ekul liberou a entrada do RU!\n");
    }

    return 0;
}
