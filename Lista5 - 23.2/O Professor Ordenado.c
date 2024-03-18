#include <stdio.h>

void bubbleInverso(int contador, int limite, int array[]){
    if(contador<0) return;
    bubbleInverso(contador-1, limite, array);
    if(array[contador]<array[contador+1] && contador+1<limite){
        array[contador]=array[contador]^array[contador+1];
        array[contador+1]=array[contador+1]^array[contador];
        array[contador]=array[contador]^array[contador+1];
    }
}

void bubbleShortInverso(int contador, int rep, int array[]){
    if(contador<0) return;
    bubbleInverso(rep, rep, array);
    bubbleShortInverso(contador-1, rep, array);
}

void bubble(int contador, int limite, int array[]){
    if(contador<0) return;
    bubble(contador-1, limite, array);
    if(array[contador]>array[contador+1] && contador+1<limite){
        array[contador]=array[contador]^array[contador+1];
        array[contador+1]=array[contador+1]^array[contador];
        array[contador]=array[contador]^array[contador+1];
    }
}

void bubbleShort(int contador, int rep, int array[]){
    if(contador<0) return;
    bubble(rep, rep, array);
    bubbleShort(contador-1, rep, array);
}

void myFor(int contador, int array[]){
    if(contador<0) return;
    myFor(contador-1, array);
    scanf("%d", &array[contador]);
}

void imprimir(int contador, int array[]){
    if(contador<0) return;
    imprimir(contador-1, array);
    if(contador==9){
        printf("%d\n", array[contador]);
        return;
    }    
    printf("%d ", array[contador]);
}

void myWhile(int contador){
    if(!contador) return ;
    myWhile(contador-1);
    int notas[10];
    myFor(9, notas);
    printf("turma: %d\n", contador);
    bubbleShort(9, 9, notas);
    imprimir(9, notas);
    bubbleShortInverso(9, 9, notas);
    imprimir(9, notas);

}
int main(){
    int qtnRep;
    scanf("%d", &qtnRep);
    myWhile(qtnRep);
    return 0;
}