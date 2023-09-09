#include <stdio.h>
int multiplo(int n, int variante, int fim,int inexistente){
    if(variante<=fim){
        if(variante%n==0){
            printf("%d\n",variante);
            inexistente=1;
        }
        return multiplo(n,variante+1,fim,inexistente);
    }if(!inexistente){
        printf("INEXISTENTE");
    }
}
int main() {
    int numero,inicioIntervalor,fimIntervalo;
    scanf("%d%d%d",&numero,&inicioIntervalor,&fimIntervalo);
    multiplo(numero,inicioIntervalor,fimIntervalo,0);
	return 0;
}