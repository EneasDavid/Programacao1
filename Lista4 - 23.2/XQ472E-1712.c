#include <stdio.h>
void conversor(int entrada){
    if(entrada==0) return;
    printf("%c", (entrada%10)%2==0?'.':'-');
    conversor(entrada/10);
}
void myFor(int contador){
    if(!contador) return;
    int entrada;
    scanf("%d", &entrada);
    conversor(entrada);
    printf("\n");
    myFor(contador-1);
}
int main(){
    myFor(10);
    return 0;
}