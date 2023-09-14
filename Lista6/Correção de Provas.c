#include <stdio.h>
#define MAX 10
#define MAXALUNO 100

//calcular a pontua??o de um aluno
int correcao(char gabarito[], char resposta[], int contador) {
    if (contador < MAX) {
        if (gabarito[contador] == resposta[contador]) {
            return 1 + correcao(gabarito, resposta, contador + 1);
        }
        return correcao(gabarito, resposta, contador + 1);
    }
    return 0;
}

//preencher um array de caracteres
void preencher(char myArray[], int posicao) {
    if (posicao < MAX) {
        scanf(" %c", &myArray[posicao]); //espa?o antes do %c para ignorar espa?os em branco
        preencher(myArray, posicao + 1);
    }
    return;
}

void myWhile(int notasAlunos[][2], int acertos[], char gabarito[], int frequenciaNotas[], int *contador){
    int entrada;
    scanf("%d", &entrada);
    if(entrada!=9999){
        char resposta[MAX];
        preencher(resposta, 0);
        int pontuacao=correcao(gabarito, resposta, 0);
        notasAlunos[*contador][0]=entrada;
        notasAlunos[*contador][1]=pontuacao;
        acertos[*contador]=pontuacao;
        //registra a frequ?ncia da pontua??o
        frequenciaNotas[pontuacao]++;
        printf("%d %.1lf\n", notasAlunos[*contador][0], (double)notasAlunos[*contador][1]);
        (*contador)++;
        myWhile(notasAlunos, acertos, gabarito, frequenciaNotas, contador);
    }    
    return ;
}

int myFor(int notaBase, int repeticaoNota[]){
    if(notaBase<11){
        return repeticaoNota[notaBase]+myFor(notaBase+1, repeticaoNota);
    }
    return 0;
}
void percorrerArray(int myArray[], int loop, int *mais, int qtn){
    if(loop==11){
        return;
    }
    if(myArray[loop]>=qtn){
        *mais=loop;
        qtn=myArray[loop];
    }
    percorrerArray(myArray,loop+1,mais,qtn);
}

int main() {
    char gabarito[MAX], provaSala[MAXALUNO][MAX];
    int notasAlunos[MAXALUNO][2], acertos[MAXALUNO], contador=0, aprovados=0, maisAparece=0,frequenciaNotas[11]={0};
    preencher(gabarito, 0);
    //fun??o pra ler as respostas dos cornos
    myWhile(notasAlunos, acertos, gabarito, frequenciaNotas, &contador);
    //pra calcular a porcentagem de aprova??o
    aprovados=myFor(6,frequenciaNotas);
    double percentualAprovacao = (double)aprovados/contador*100;
    percorrerArray(frequenciaNotas, 0, &maisAparece, 0);

    printf("%.1lf%%\n", percentualAprovacao);
    printf("%d.0\n", maisAparece);
    return 0;
}
