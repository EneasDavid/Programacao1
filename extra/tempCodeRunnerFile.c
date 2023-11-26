#include <stdio.h>

int calcularTamanhoDoCiclo(int numero) {
    if(numero==1){
        return 1;
    }else if(numero%2==0){
        numero/=2;
    }else{
        numero=(3*numero)+1;
    }
    return 1+calcularTamanhoDoCiclo(numero);
}

int main(){