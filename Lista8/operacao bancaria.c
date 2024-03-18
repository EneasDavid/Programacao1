#include <stdio.h>

int main() {
    double operacoes[100][2]; // Assumindo um máximo de 100 operações
    double credito=0, debito=0;
    int contador=0;
    while (1) {
        int tipo;
        double valor;
        scanf("%d %lf", &tipo, &valor);
        if (tipo==-1) {
            break; // Finaliza a leitura quando encontra -1
        }
        operacoes[contador][0]=tipo;
        operacoes[contador][1]=valor;
        contador++;
    }
    for (int i=0; i<contador; i++) {
        if(operacoes[i][0]==0) debito+=operacoes[i][1];
        else if(operacoes[i][0]==1) credito+=operacoes[i][1];
    }
    printf("Creditos: R$ %.2lf\nDebitos: R$ %.2lf\nSaldo: R$ %.2lf", credito, debito, credito-debito);
    return 0;
}
