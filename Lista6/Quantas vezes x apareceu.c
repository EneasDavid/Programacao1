#include <stdio.h>
void laco(int myArray[], int tamanho, int loop){
    if(tamanho>loop){
        scanf("%d", &myArray[loop]);
        laco(myArray, tamanho, loop+1);
    }
}
int buscar(int myArray[], int tamanho, int loop, int busca){
    if(loop<tamanho){
        if(myArray[loop]==busca){
            return 1+buscar(myArray, tamanho, loop+1, busca);
        }        
        return buscar(myArray, tamanho, loop+1, busca);
    }
    return 0;
}
int main() {
    int lista[11], busca;
    laco(lista, 10, 0);
    scanf("%d", &busca);
    printf("%d",buscar(lista, 10, 0, busca));
    return 0;
}