#include <stdio.h>
void myFor(int inicio, int fim){
    if(inicio>fim) return ;
    //x**2 - 4*x + 5
    printf("%d\n", (inicio*inicio-4*inicio+5));
    return myFor(inicio+1, fim);
}
int main(){
    int x, y;
    scanf("%d%d", &x,&y);
    myFor(x,y);
    return 0;
}