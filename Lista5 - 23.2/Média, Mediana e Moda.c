#include <stdio.h>

void bubble(int contador, int array[]){
    if (contador<0) return;
    if (array[contador]>array[contador-1]){
        int auxiliar=array[contador];
        array[contador]=array[contador-1];
        array[contador-1]=auxiliar;
    }
    bubble(contador-1, array);
}

void bubble_sort(int contador, int vBubble, int array[]) {
    if (!contador) return;
    bubble(vBubble, array);
    bubble_sort(contador-1, vBubble, array);
}

double mediana(int contador, int array[]) {
    if (!(contador%2)) return array[contador>>1];
    else return (double)(array[(int)contador>>1]+array[((int)contador>>1)+1])/2;
}

double somarArray(int repetidor, int myArray[]) {
    if (!repetidor) return 0;
    return (double)myArray[repetidor-1]+somarArray(repetidor-1, myArray);
}

int contarFrequencia(int i, int contador, int array[], int valorBusca) {
    if (i==contador) return 0;
    return valorBusca==array[i]?1+contarFrequencia(i+1, contador, array, valorBusca):contarFrequencia(i+1, contador, array,valorBusca);
}

double modaRecursiva(int i, int contador, int array[], int frequenciaMax, int mode) {
    if(i==contador) return (double)mode;
    int count = contarFrequencia(0, contador, array, array[i]);
    if(count>frequenciaMax) return modaRecursiva(i+1, contador, array, count, array[i]);
    else return modaRecursiva(i+1, contador, array, frequenciaMax, mode);
}

double moda(int contador, int array[]) {
    return (double)modaRecursiva(0, contador, array, 0, -1);
}

void imprimir(int repetidor, int myArray[]) {
    if (!repetidor) return;
    printf("%d ", myArray[repetidor-1]);
    imprimir(repetidor-1, myArray);
}

void myFor(int repetidor, int myArray[]) {
    if (!repetidor) return;
    scanf("%d", &myArray[repetidor-1]);
    myFor(repetidor-1, myArray);
}

int main() {
    int n;
    scanf("%d", &n);
    int array[n];
    myFor(n, array);
    bubble_sort(n-1, n-1, array);
    double soma = somarArray(n, array);
    printf("%.2lf %.2lf %.2lf\n", soma/n, mediana(n-1, array), moda(n, array));
    return 0;
}