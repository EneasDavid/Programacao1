#include <stdio.h>

int calcularTamanhoDoCiclo(int numero) {
    if(numero==1) {
        return 1;
    } else if(numero%2==0) {
        numero/=2;
    } else {
        numero=(3*numero)+1;
    }
    return 1+calcularTamanhoDoCiclo(numero);
}
void myFor(int i, int fim, int *maiorTamanhoCiclo) {
    if (i<=fim) {
        int tamanhoAtual=calcularTamanhoDoCiclo(i);
        if (tamanhoAtual>*maiorTamanhoCiclo) {
            *maiorTamanhoCiclo=tamanhoAtual;
        }
        myFor(i + 1, fim, maiorTamanhoCiclo);
    }
}
void myWhile(){
    int inicio, fim, maiorTamanhoCiclo;
    if (scanf("%d %d", &inicio, &fim)==EOF) {
            return ;
        }
        maiorTamanhoCiclo=0;
        if(inicio<=fim){
            myFor(inicio, fim, &maiorTamanhoCiclo);
        }else{
            myFor(fim, inicio, &maiorTamanhoCiclo);
        }
            /*
            for (int i=inicio;i<=fim;i++) {
                int tamanhoAtual=calcularTamanhoDoCiclo(i);
                if (tamanhoAtual>maiorTamanhoCiclo) {
                    maiorTamanhoCiclo=tamanhoAtual;
                }
            }
            */
        printf("%d %d %d\n", inicio, fim, maiorTamanhoCiclo);
        myWhile();
}
int main() {
    myWhile();
    return 0;
}
/*
função calcularTamanhoDoCiclo(numero):
    tamanhoCiclo = 1 
    enquanto numero ≠ 1:
        se numero%2==0:
            numero = numero / 2
        senão:
            numero = 3 * numero + 1
        tamanhoCiclo = tamanhoCiclo + 1
    retornar tamanhoCiclo
enquanto houver entrada:
    ler inicio e fim da entrada
    maiorTamanhoCiclo = 0
    para cada numeroAtual de inicio até fim:
        tamanhoAtual = calcularTamanhoDoCiclo(numeroAtual)
        se tamanhoAtual > maiorTamanhoCiclo:
            maiorTamanhoCiclo = tamanhoAtual
    imprimir inicio, fim e maiorTamanhoCiclo
*/