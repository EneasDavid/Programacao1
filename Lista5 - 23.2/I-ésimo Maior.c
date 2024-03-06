#include <stdio.h>

void myFor(int array[], int contador){
    if(contador) myFor(array, contador-1); //garantir que a leitura seja em ordem
    scanf("%d", &array[contador]);
}

void bubble(int contador, int array[]){
    if(contador<0) return;
    if(array[contador]<array[contador+1]) { //Ordenar do maior para o menor
        array[contador]=array[contador]^array[contador+1];
        array[contador+1]=array[contador+1]^array[contador];
        array[contador]=array[contador]^array[contador+1];
    }
    bubble(contador-1, array);
}

void bubble_short(int contador, int vBubble, int array[]){
    if(!contador) return;
    bubble(vBubble, array);
    bubble_short(contador-1, vBubble, array);
}

int main(){
    int numero, valor;
    scanf("%d %d", &numero, &valor);
    int  myArray[numero];
    myFor(myArray, numero-1);
    /*for(int i=0;i<numero;i++){
        printf("myArray[%d]:%d\n", i, myArray[i]);
    }*/
    bubble_short(numero-1, numero-1, myArray);
    /*for(int i=0;i<numero;i++){
        printf("myArray[%d]:%d\n", i, myArray[i]);
    }*/
    printf("%d\n", myArray[valor-1]);
    return 0;
}