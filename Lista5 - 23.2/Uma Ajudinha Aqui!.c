#include <stdio.h>

void imprimir(int contador, int limite, double array[]){
    if(contador<0) return;
    imprimir(contador-1, limite, array);
    if(contador==limite){
        printf("%.2lf\n", array[contador]);
        return;
    } 
    printf("%.2lf ", array[contador]);
}


void bubble(int contador, int limite, double array[]){
    if (contador<0) return;
    if(array[contador]>array[contador-1] && contador-1>-1){
        double auxiliar=array[contador-1];
        array[contador-1]=array[contador];
        array[contador]=auxiliar;
    }
    bubble(contador-1, limite, array);
}

void bubbleShort(int contador, int contBubble, double array[]){
    if(contador<0) return;
    bubble(contBubble, contBubble, array);
    bubbleShort(contador-1, contBubble, array);
}

void myFor(int contador, double arrayEC[], double arrayCC[], int contCC, int contEC){
    if(contador<0) {
        bubbleShort(contEC, contEC, arrayEC);
        bubbleShort(contCC, contCC, arrayCC);
        printf("EC:\n");
        imprimir(contEC-1, contEC-1, arrayEC);
        printf("CC:\n");
        imprimir(contCC-1, contCC-1, arrayCC);
        return;
    }
    double entrada;
    char turma;
    scanf("%lf %c", &entrada, &turma);
    if(turma=='e'){
        arrayEC[contEC]=entrada;
        myFor(contador-1, arrayEC, arrayCC, contCC, contEC+1);
    }
    else{
        arrayCC[contCC]=entrada;
        myFor(contador-1, arrayEC, arrayCC, contCC+1, contEC);
    }
}

int main(){
    double EC[10], CC[10];
    myFor(9, EC, CC,0,0);
    return 0;    
}