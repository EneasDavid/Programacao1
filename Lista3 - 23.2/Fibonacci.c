#include <stdio.h>
void fibonacci(int repeticoes,int variante, int atual){
    if(!repeticoes){
        printf("%d\n", variante);    
        return;
    } 
    printf("%d ", variante);
    fibonacci(repeticoes-1, variante+atual, variante);
}
void myWhile(){
    int entrada;
    scanf("%d", &entrada);
    if(entrada){
        fibonacci(entrada-1, 0, 1);
        myWhile();
    } 
}
int main(){
    myWhile();
    return 0;
}