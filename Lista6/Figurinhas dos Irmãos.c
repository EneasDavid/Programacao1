#include <stdio.h>

void repetida(int myArray[], int tamanho, int i, int j){
    if(i<tamanho){
        if(j<tamanho){
            if(i!=j){
                if(myArray[i]==myArray[j]){
                    myArray[j]=0;
                    return repetida(myArray, tamanho, i, j+1);
                }
            }
            return repetida(myArray, tamanho, i, j+1);
        }
        return repetida(myArray, tamanho, i+1, 0);
    }
    return ;
}

void calculandoFigurinhas(int myArray[], int tamanho, int *pontos, int i){
    if(i<tamanho){
        repetida(myArray, tamanho, i, i);
        *pontos+=myArray[i];
        calculandoFigurinhas(myArray, tamanho, pontos, i+1);
    }
    return ;
}

void myFor(int maria[], int joao[], int tamanho, int *tamanhoJoao, int *tamanhoMaria, int loop){
    if(loop<tamanho){
        int figuinha;
        scanf("%d", &figuinha);
        if(figuinha%2){
            joao[*tamanhoJoao] = figuinha;
            (*tamanhoJoao)++;
        }else{
            maria[*tamanhoMaria] = figuinha;
            (*tamanhoMaria)++;
        }
        myFor(maria, joao, tamanho, tamanhoJoao, tamanhoMaria, loop+1);
    }
    return ;
}

int main(){
    int tamanho, tamanhoMaria=0, mariaPonto=0, tamanhoJoao=0, joaoPonto=0, maior=0;
    scanf("%d", &tamanho);
    int figurinhas[tamanho], maria[tamanho], joao[tamanho];
    myFor(maria, joao, tamanho, &tamanhoJoao, &tamanhoMaria, 0);
    calculandoFigurinhas(maria, tamanhoMaria,&mariaPonto, 0);
    calculandoFigurinhas(joao, tamanhoJoao, &joaoPonto, 0);
    if(mariaPonto>joaoPonto){
        printf("%d\n%d\n%d",tamanhoMaria,tamanhoJoao,mariaPonto);
    }else{
        printf("%d\n%d\n%d",tamanhoMaria,tamanhoJoao,joaoPonto);
    }
    return 0;
}