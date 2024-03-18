#include <stdio.h>
#include <string.h>
#define MAX 100

void inverter(char meuArray[], int loop){
    if(loop>-1){
        printf("%c", meuArray[loop]);
        inverter(meuArray,loop-1);
    }
    return;
}

int main() {
    char vetor[MAX];
    scanf("%s", vetor);
    inverter(vetor, strlen(vetor));
	return 0;
}