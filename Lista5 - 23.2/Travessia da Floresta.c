#include <stdio.h>
void preencherArray(int qtnRep, int array[]){
    if(qtnRep<0) return;
    preencherArray(qtnRep-1, array);
    scanf("%d", &array[qtnRep]);
}
void somador(int contador, int jogada[], int bonus[], int soma[]){
    if(contador<0) return;
    somador(contador-1, jogada, bonus, soma);
    soma[contador]=jogada[contador]+bonus[contador];
}
int passouFloresta(int contador, int nivelFloresta, int array[]){
    if(contador<0) return 0;
    return array[contador]>=nivelFloresta?1+passouFloresta(contador-1, nivelFloresta, array):passouFloresta(contador-1, nivelFloresta, array);
}
void bubble(int contador,  int limite, int array[]){
    if(contador<0) return;
    bubble(contador-1, limite, array);
    //printf("array[%d]:%d<array[%d]:%d=%d\n", contador, array[contador], contador+1, array[contador+1], array[contador]<array[contador+1]);
    if(array[contador]<array[contador+1] && contador+1<=limite){
        array[contador]=array[contador]^array[contador+1];
        array[contador+1]=array[contador+1]^array[contador];
        array[contador]=array[contador]^array[contador+1];
    }
}
void bubbleShort(int contador, int tamanho, int array[]){
    if(contador<0) return;
    bubble(tamanho, tamanho, array);
    bubbleShort(contador-1, tamanho, array);
}

int main(){
    int nivelDificuldade, jogada[5], bonus[5], jogadaSomada[5];
    scanf("%d", &nivelDificuldade);
    preencherArray(4,jogada);
    preencherArray(4,bonus);
    somador(4, jogada, bonus, jogadaSomada);
    bubbleShort(4, 4, jogadaSomada);
    printf("Jogadores que passaram: %d\nMaior valor: %d\nMenor valor: %d", passouFloresta(4, nivelDificuldade, jogadaSomada),jogadaSomada[0], jogadaSomada[4]);
   return 0; 
}