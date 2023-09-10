#include <stdio.h>
void entrada(int *pNumeroVez){
    int entradaLoop;
    scanf("%d", &entradaLoop);
    if(entradaLoop!=0){
        if (*pNumeroVez<entradaLoop){
           *pNumeroVez=entradaLoop;
        }
        entrada(pNumeroVez);
    }
    return;
}
int main(){
    int numeroVez=0;
    entrada(&numeroVez);
    printf("%d", numeroVez);
    return 0;
}