#include <stdio.h>
int valor(int x, int y, int z, int d, int valoVez, int desconto){
    int valorTemp=(d+(desconto*z))*(y-desconto);
    if (valoVez<valorTemp) valoVez=valorTemp;
    if(x+desconto==y) return valoVez;
    return valor(x,y,z,d,valoVez,desconto+1);
}
int main(){
    int valorMininoIngreso, valorMaximoIngreso, qtnIngresoDesconto, qtnIngresoVMaximo;
    scanf("%d%d%d%d",&valorMininoIngreso,&valorMaximoIngreso,&qtnIngresoDesconto,&qtnIngresoVMaximo);
    printf("%d",valor(valorMininoIngreso,valorMaximoIngreso,qtnIngresoDesconto,qtnIngresoVMaximo,0,0));
    return 0;
}
/*å
 o primeiro é  o valor mínimo do ingresso
 o segundo o valor máximo do ingresso
 o terceiro valor é a quantidade de ingressos que vai aumentar a cada real a mais de desconto
 o quarto valor é a quantidade de ingressos inicial para o valor máximo.
*/