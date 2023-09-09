#include <stdio.h>

int main(){
    int entradaUm, entradaDois;

    scanf("%d", &entradaUm);
    scanf("%d", &entradaDois);

    if(entradaUm>=entradaDois){
        printf("%d %d", entradaDois, entradaUm);
    }else{
        printf("%d %d", entradaUm, entradaDois);
    }
    
    return 0;
}