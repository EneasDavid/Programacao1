#include <stdio.h>

void calculandoFigurinhas(int myArray[], int tamanho, int *pontosMaria, int *pontosJoao, int i){
    if(i<tamanho){
        if(myArray[i]!=0){
            if(myArray[i]%2==0){
                *pontosJoao+=myArray[i];
            }else{
                *pontosMaria+=myArray[i];
            }
        }
        calculandoFigurinhas(myArray, tamanho, pontosMaria, pontosJoao, i+1);
    }
}

void repetida(int myArray[], int tamanho, int i, int j){
    if(i<tamanho){
        if(j<tamanho){
            if(i!=j){
                if(myArray[i]==myArray[j]){
                    myArray[j]=0;
                }
            }
            repetida(myArray, tamanho, i, j+1);
        }
        repetida(myArray, tamanho, i+1, 0);
    }
}

void myFor(int myArray[], int tamanho, int *tamanhoJoao, int *tamanhoMaria, int loop){
    if(loop<tamanho){
        int figuinha;
        scanf("%d", &figuinha);
        myArray[loop] = figuinha;
        if(figuinha%2){
            (*tamanhoJoao)++;
        }else{
            (*tamanhoMaria)++;
        }
        myFor(myArray, tamanho, tamanhoJoao, tamanhoMaria, loop+1);
    }
    return ;
}

int main(){
    int tamanho, tamanhoMaria=0, mariaPonto=0, tamanhoJoao=0, joaoPonto=0, maior=0;
    scanf("%d", &tamanho);
    int figurinhas[tamanho];
    myFor(figurinhas, tamanho, &tamanhoJoao, &tamanhoMaria, 0);
    repetida(figurinhas, tamanho, 0, 0);
    calculandoFigurinhas(figurinhas, tamanho, &mariaPonto, &joaoPonto, 0);
    if(mariaPonto>joaoPonto){
        printf("%d\n%d\n%d",tamanhoMaria,tamanhoJoao,mariaPonto);
    }else{
        printf("%d\n%d\n%d",tamanhoMaria,tamanhoJoao,joaoPonto);
    }
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void soma(int *joao, int *maria, int figurinhas[], int aux, int tamanho)
{
    if (aux == tamanho)
    {
        return;
    }

    if (figurinhas[aux] % 2 == 0)
    {
        joao[1] += figurinhas[aux];
    }
    else
    {
        maria[1] += figurinhas[aux];
    }

    soma(joao, maria, figurinhas, aux + 1, tamanho);
}

void repetidas(int *figurinhas, int i, int j, int tamanho)
{
    if (i == tamanho)
    {
        return;
    }

    if (figurinhas[i] == figurinhas[j])
    {
        figurinhas[j] = 0;
    }

    if (figurinhas[j] == tamanho)
    {
        repetidas(figurinhas, i + 1, i + 2, tamanho);
    }
    else
    {
        repetidas(figurinhas, i, j + 1, tamanho);
    }
}

void batalha(int figurinhas[], int joao[], int maria[], int tamanho, int aux)
{
    if (tamanho == aux)
    {
        printf("%d\n", joao[0]);
        printf("%d\n", maria[0]);

        repetidas(figurinhas, 0, 1, tamanho);

        soma(joao, maria, figurinhas, 0, tamanho);

        if (joao[1] > maria[1])
        {
            printf("%d", joao[1]);
        }
        else
        {
            printf("%d", maria[1]);
        }

        return;
    }

    if (figurinhas[aux] % 2 == 0)
    {
        joao[0] += 1;
    }
    else
    {
        maria[0] += 1;
    }

    batalha(figurinhas, joao, maria, tamanho, aux + 1);
}

void ler(int figurinhas[], int tamanho, int aux)
{
    if (aux == tamanho)
    {
        return;
    }

    scanf("%d", &figurinhas[aux]);

    ler(figurinhas, tamanho, aux + 1);
}

int main()
{
    int tamanho;

    scanf("%d", &tamanho);

    int figurinhas[tamanho];
    int joao[2] = {0, 0};
    int maria[2] = {0, 0};

    ler(figurinhas, tamanho, 0);

    batalha(figurinhas, joao, maria, tamanho, 0);

    return 0;
}
*/