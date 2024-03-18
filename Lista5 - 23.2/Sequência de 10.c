#include <stdio.h>

void myFor(int array[], int contador){
    if(contador) myFor(array, contador-1); //garantir que a leitura seja em ordem
    scanf("%d", &array[contador]);
}

int buscar(int array[], int contador){
    if(contador<0) return 0;
    return array[9]==array[contador]?1+buscar(array,contador-1):buscar(array,contador-1);
}
int main(){
    int myArray[10];
    myFor(myArray, 9);
    printf("O numero %d apareceu %d vezes\n", myArray[9], buscar(myArray, 10));
    return 0;
}