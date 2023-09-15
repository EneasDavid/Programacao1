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
        myArray[loop] = figuinha; // Armazenar a figurinha no array
        if(figuinha%2){
            (*tamanhoMaria)++;
        }else{
            (*tamanhoJoao)++;
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
