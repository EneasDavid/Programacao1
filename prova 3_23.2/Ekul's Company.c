#include <stdio.h>

void bubble(float array[], int contador){
    if(contador<0) return ;
    if(array[contador]>array[contador-1] && contador-1>-1){
        float aux=array[contador];
        array[contador]=array[contador-1];
        array[contador-1]=aux;
    }
    bubble(array, contador-1);
}

void bubbleShort(float array[], int contador, int contadorBubble){
    if(contador<0) return;
    bubble(array, contadorBubble);
    bubbleShort(array, contador-1, contadorBubble);
}

int contaVagas(float array[], int contador, int limite, int contDaVaga){
    if(array[contDaVaga]==1){
        contaVagas(array, 0, limite, contador+1);
        return 0;
    } 
    if(contador==limite){
        array[contDaVaga]=1;
        contaVagas(array, 0, limite, 0);
        return 1;
    }
    if(array[contDaVaga]+array[contador]<=1 && contDaVaga!=contador){
        array[contDaVaga]=1;
        array[contador]=1;
        return 1;
    }
    return contaVagas(array, contador+1, limite, contDaVaga);
}

void myFor(int contador, float array[]){
    if(contador<0) return;
    myFor(contador-1, array);
    scanf("%f", &array[contador]);
}

int main(){
    int qtnCarros;
    scanf("%d", &qtnCarros);
    float arrayCarros[qtnCarros];
    myFor(qtnCarros, arrayCarros);
    bubbleShort(arrayCarros, qtnCarros-1, qtnCarros-1);
    //for(int i=0;i<qtnCarros;i++) printf("%.2lf\n", arrayCarros[i]);
    int saida=contaVagas(arrayCarros, 0, qtnCarros, 0);
    printf("%d\n", saida>0?saida:qtnCarros);    
    return 0;
}