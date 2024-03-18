#include <stdio.h>

int main(){
    int numUm, numDois;
    scanf("%d %d", &numUm, &numDois);
    for(int i=1;i<=numDois;i++){
        int contador=numUm;
        if(i%contador==0){
            printf("%d\n",i);
            contador=0;
        }else{
            printf("%d ",i);
            contador++;
        }
    }
    return 0;
}