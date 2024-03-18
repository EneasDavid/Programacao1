#include <stdio.h>

void bubble(int array[], int contador){
    if(contador<0) return ;
    if(array[contador]>array[contador-1] && contador-1>-1){
        array[contador]=array[contador]^array[contador-1];
        array[contador-1]=array[contador-1]^array[contador];
        array[contador]=array[contador]^array[contador-1];
    }
    bubble(array, contador-1);
}

void bubbleShort(int array[], int contador, int contadorBubble){
    if(contador<0) return;
    bubble(array, contadorBubble);
    bubbleShort(array, contador-1, contadorBubble);
}

int sequencia(int contador, int limite, int array[], int rep, int repAnterior) {
    if(contador==limite) return rep>repAnterior?rep:repAnterior;
    return array[contador]!=array[contador+1]?sequencia(contador+1, limite, array, rep+1, repAnterior):sequencia(contador+1, limite, array, 1, rep);
}

void myFor(int contador, int array[]){
    if(contador<0) return;
    myFor(contador-1, array);
    scanf("%d", &array[contador]);
}

void myWhile(int contador, int reps[]){
    if(contador<0) return;
    myWhile(contador-1, reps);
    int tamanhoArray;
    scanf("%d", &tamanhoArray);
    int array[tamanhoArray];
    myFor(tamanhoArray-1, array);
    reps[contador]=sequencia(0, tamanhoArray-1, array, 1, 1);
}

int main(){
    int rep;
    scanf("%d", &rep);
    int sequencia[rep];
    myWhile(rep-1, sequencia);
    bubbleShort(sequencia, rep-1, rep-1);
    printf("%d", sequencia[0]);
    return 0;
}