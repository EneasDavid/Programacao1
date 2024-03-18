#include <stdio.h>

int main(){
    int numUm, numDois, variante, posicao=1;
    scanf("%d %d %d", &numUm, &numDois, &variante);
    for(int i=1;i<=numDois;i+=variante){
        if(numUm==posicao){
            printf("%d\n",i);
            posicao=1;
        }else{
            printf("%d ",i);
            posicao++;
        }
    }
    return 0;
}