#include <stdio.h>

int boolBalanceada(int F, int array[], int contador){
    if(contador<0) return 0;
    if(array[contador]==F) return 1+boolBalanceada(F, array, contador-1);  
    else return -1+boolBalanceada(F, array, contador-1);
}

void myFor(int contador, int array[]){
    if(contador<0) return;
    myFor(contador-1, array);
    scanf("%d", &array[contador]);
}

int main(){
    int  A, F, T;
    //A- indica o n?mero que indica se ? '('
    //F - indica o n?mero que indica se ? ')'
    //T - indica a quantidade de valores que ?o de entrar
    scanf("%d%d%d", &A, &F, &T);
    if(T%2) printf("Desbalanceada!\n");
    else{
        int array[T];
        myFor(T-1, array);
        if(array[0]==F) printf("Desbalanceada!\n");
        else printf("%s", boolBalanceada(F, array ,T-1)==0?"Balanceada!":"Desbalanceada!\n");
    }
    return 0;
}