#include <stdio.h>

void soma(int *joao, int *maria, int figurinhas[], int aux, int tamanho){
    if (aux == tamanho){
        return;
    }
    if (figurinhas[aux]%2==0){
        joao[1]+=figurinhas[aux];
    }else{
        maria[1]+=figurinhas[aux];
    }
    soma(joao, maria, figurinhas, aux+1, tamanho);
}

void repetidas(int *figurinhas, int i, int j, int tamanho){
    if (i==tamanho){
        return;
    }
    if (figurinhas[i]==figurinhas[j]){
        figurinhas[j]=0;
    }
    if (figurinhas[j]==tamanho){
        repetidas(figurinhas, i+1, i+2, tamanho);
    }else{
        repetidas(figurinhas, i, j+1, tamanho);
    }
}

void batalha(int figurinhas[], int joao[], int maria[], int tamanho, int aux){
    if (tamanho==aux){
        printf("%d\n", joao[0]);
        printf("%d\n", maria[0]);
        repetidas(figurinhas, 0, 1, tamanho);
        soma(joao, maria, figurinhas, 0, tamanho);
        if (joao[1]>maria[1]){
            printf("%d", joao[1]);
        }else{
            printf("%d", maria[1]);
        }
        return;
    }
    if (figurinhas[aux]%2==0){
        joao[0]+=1;
    }else{
        maria[0]+=1;
    }
    batalha(figurinhas, joao, maria, tamanho, aux + 1);
}

void ler(int figurinhas[], int tamanho, int aux){
    if (aux==tamanho){
        return;
    }
    scanf("%d", &figurinhas[aux]);
    ler(figurinhas, tamanho, aux+1);
}

int main(){
    int tamanho;
    scanf("%d", &tamanho);
    int figurinhas[tamanho];
    int joao[2] = {0};
    int maria[2] = {0};
    ler(figurinhas, tamanho, 0);
    batalha(figurinhas, joao, maria, tamanho, 0);
    return 0;
}