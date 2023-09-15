#include <stdio.h>

int contaToca(int i, int loop, int tamanho, int myArray[]){
	if(loop < tamanho){
        int contagem = (myArray[i] == loop) ? 1 : 0;
        if(contagem == 0){
            return contagem + contaToca(i + 1, loop, tamanho, myArray);
        }else{
            return contagem + contaToca(i, loop + i, tamanho, myArray);
        }
    }
	return 0;
}
void myFor(int myArray[], int loop, int tamanho){
    if(loop<tamanho){
	    scanf("%d", &myArray[loop]);
    	myFor(myArray, loop + 1, tamanho);
	}
	return;

}

int main(){
	int entrada;
	scanf("%d", &entrada);
	int tocas[entrada];
	myFor(tocas, 0, entrada);
	printf("%d", contaToca(0, 0, entrada, tocas));
    return 0;
}