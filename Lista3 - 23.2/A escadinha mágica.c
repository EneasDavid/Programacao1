#include <stdio.h>
int myForAlinhado(int i, int max){
    if(i==max){
        printf("%d", i);
        return 0;
    }
    printf("%d ", i);
    myForAlinhado(i+1,max);
}
int myFor(int i, int max){
    if(i==max){
        return 0;
    }
    myForAlinhado(1,i);
    printf("\n");
    return myFor(i+1, max);
}

int main(){
    int entrada;
    scanf("%d",&entrada);
    myFor(1,entrada+1);
    return 0;
}