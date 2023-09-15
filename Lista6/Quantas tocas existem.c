#include <stdio.h>

void ler(int myArray[], int posicao, int tamanho){
    if (posicao<tamanho){
        scanf("%d", &myArray[posicao]);
        return ler(myArray, posicao+1, tamanho);
    }
	return;
}

void rep(int myArray[], int posicao){
    if (myArray[posicao]!=-1){
        int box=myArray[posicao];
        myArray[posicao]=-1;
        return rep(myArray, box);    
    }
	return;
}

void toc(int myArray[], int posicao, int tamanho, int toca){
    if(posicao<tamanho){
        if(myArray[posicao]!=-1){
            rep(myArray, posicao);
            return toc(myArray,posicao+1,tamanho,toca+=1);
        }
        return toc(myArray, posicao+1, tamanho, toca);
    }
	printf("%d\n", toca);
    return;
}

int main (){
    int tamanho;
    scanf("%d", &tamanho);
    int buraco[tamanho];
    ler(buraco, 0, tamanho);
    toc(buraco, 0, tamanho, 0);
    return 0;
}
