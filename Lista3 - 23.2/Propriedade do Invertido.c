#include <stdio.h>
/*
entrada/(entrada/10)
entrada%10!=0
*/
void intervalo(int x, int y, int variante){
    if(variante>y) return ;
    if((variante%10!=0) && (variante%(variante/10))==0) printf("%d\n", variante);
    intervalo(x,y,variante+1);
}
int main(){
    int x, y;
    scanf("%d%d", &x,&y);
    if(x<10 || y>100) return 0;
    intervalo(x,y, x);
    return 0;
}