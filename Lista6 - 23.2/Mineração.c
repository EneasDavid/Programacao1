#include <stdio.h>

int acharSaida(int array[], int saida){
    if(array[saida]==-1) return saida;
    return acharSaida(array, array[saida]);
}

void myFor(int contador, int array[]){
    if(contador<0) return;
    myFor(contador-1, array);
    scanf("%d", &array[contador]);
}

int main(){
    int qtnTunes, saida;
    scanf("%d", &qtnTunes);
    int array[qtnTunes];
    myFor(qtnTunes-1, array);
    scanf("%d", &saida);
    printf("%d", acharSaida(array, saida));
    return 0;
}