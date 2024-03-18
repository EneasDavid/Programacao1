#include <stdio.h>
quemVenceu(int entrada, int nando, int dunga){
    int variante=entrada%10;
    if(variante>=0 && entrada>0){
        if(variante%2==0){
            dunga+=variante;
        }else{
            nando+=variante;
        }
        return quemVenceu((entrada-variante)/10,nando,dunga);
    }
    if(dunga>nando){
        printf("Vencedor: Dunga\n%d Pontos de Vantagem",dunga-nando);
    }else if(nando>dunga){
        printf("Vencedor: Nando\n%d Pontos de Vantagem",nando-dunga);
    }else{
        printf("Empate");
    }
    return 0;
}
int main() {
    int entrada;
    scanf("%d",&entrada);
    quemVenceu(entrada,0,0);
	return 0;
}