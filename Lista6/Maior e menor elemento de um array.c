#include <stdio.h>
void myFor(int myArray[], int tamanho,int loop){
    if(loop<tamanho){
        scanf("%d", &myArray[loop]);
        myFor(myArray, tamanho, loop+1);
    }
    return;
}
void maiorNumero(int myArray[], int tamanho,int loop, int *maior){
    if(loop<tamanho){
        if(*maior<myArray[loop]){
            *maior=myArray[loop];
        }
        maiorNumero(myArray, tamanho, loop+1, maior);
    }
    return;
}
void menorNumero(int myArray[], int tamanho, int loop, int *menor){
    if(loop<tamanho){
        if(*menor>myArray[loop]){
            *menor=myArray[loop];
        }
        menorNumero(myArray, tamanho, loop+1, menor);
    }
    return;
}

int main() {
    int listaDeNumeros[6], maior=0;
    myFor(listaDeNumeros, 6, 0);
    int menor=listaDeNumeros[0];
	maiorNumero(listaDeNumeros, 6, 0, &maior);
	menorNumero(listaDeNumeros, 6, 0, &menor);
	printf("%d\n%d", menor, maior);
	return 0;
}