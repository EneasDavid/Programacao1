#include <stdio.h>
#define MAX 10
#define MAXALUNO 100

// Função para calcular a pontuação de um aluno
int correcao(char gabarito[], char resposta[], int contador) {
    if (contador<MAX) {
        if (gabarito[contador]==resposta[contador]) {
            return 1+correcao(gabarito, resposta, contador+1);
        }
        return correcao(gabarito, resposta, contador+1);
    }
    return 0;
}

// Função para preencher um array de caracteres
void preencher(char myArray[], int posicao) {
    if (posicao<MAX) {
        scanf(" %c", &myArray[posicao]); // Adicionei um espaço antes do %c para ignorar espaços em branco
        preencher(myArray, posicao+1);
    }
    return;
}

// Função principal para ler os dados dos alunos
int main(){
    char gabarito[MAX], provaSala[MAXALUNO][MAX];
    int notasAlunos[MAXALUNO][2], acertos[MAXALUNO];

    preencher(gabarito, 0);

    int entrada;
    scanf("%d", &entrada);

    int contador = 0; // Adicionei um contador para controlar o número de alunos
    int maiorNota = -1; // Adicionei uma variável para rastrear a maior nota
    int frequenciaNotas[11] = {0}; // Adicionei um array para rastrear a frequência das notas

    // Enquanto o número do aluno for diferente de 9999
    while (entrada!=9999){
        char resposta[MAX];
        preencher(resposta, 0);

        int pontuacao=correcao(gabarito, resposta, 0);
        notasAlunos[contador][0]=entrada;
        notasAlunos[contador][1]=pontuacao;
        acertos[contador]=pontuacao;

        // Verifica se a pontuação é maior que a maior pontuação registrada até agora
        if (pontuacao>maiorNota) {
            maiorNota=pontuacao;
        }

        // Registra a frequência da pontuação
        frequenciaNotas[pontuacao]++;

        printf("%d %.1lf\n", notasAlunos[contador][0], (double)notasAlunos[contador][1]);

        contador++;

        scanf("%d", &entrada);
    }

    // Calcula a porcentagem de aprovação
    int aprovados=0;
    for (int i=6; i<=10; i++) {
        aprovados+=frequenciaNotas[i];
    }
    double percentualAprovacao=(double)aprovados/contador*100.0;

    printf("%.1lf%%\n", percentualAprovacao);
    printf("%d.0\n", maiorNota);

    return 0;
}
