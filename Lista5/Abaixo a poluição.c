#include <stdio.h>

double multas(int qtnCarros){
    return (qtnCarros-2)*12.89;
}

void my_while(double valorTotal, int casasMultadas){
    int entrada;
    scanf("%d", &entrada);
    if(entrada!=999){
        if(entrada>2){
            my_while(valorTotal+multas(entrada), casasMultadas+1);
        }else{
            my_while(valorTotal, casasMultadas);
        }
    }else{
        printf("%.2lf\n%d",valorTotal, casasMultadas);
    }
}
int main() {
    my_while(0,0);
	return 0;
}