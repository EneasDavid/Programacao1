#include <stdio.h>
#include <string.h>

#define MAX_INT 100

// Função que retorna o valor associado a uma determinada mídia de propaganda
double mudaValorFinal(char entrada[])
{
    // Verifica o tipo de m�dia
    if (strcmp(entrada, "Rádio") == 0)
    {
        char opcao[MAX_INT];
        scanf("%s", opcao);

        // Retorna o valor com base na opção escolhida
        if (strcmp(opcao, "AM") == 0)
        {
            return 300;
        }
        else
        {
            return 500;
        }
    }
    else if (strcmp(entrada, "TV") == 0)
    {
        int horario;
        scanf("%d", &horario);

        // Retorna o valor com base no horário de exibição
        if (horario > 20)
        {
            return 2000;
        }
        else
        {
            return 1200;
        }
    }
    else if (strcmp(entrada, "Revista") == 0)
    {
        // Retorna o valor fixo para a mídia Revista
        return 750;
    }
    else if (strcmp(entrada, "Outdoor") == 0)
    {
        // Retorna o valor fixo para a mídia Outdoor
        return 1500;
    }
    // Retorna 0 se a mídia não for reconhecida
    return 0;
}

/*
Função myFor serve para realizar a função de um laço recursivamente, tendo como parâmetros:
- i: valor máximo do intervalo
- repeticoes: quantas vezes já foram executadas (relacionado a i)
- totalArrecadacao: valor total que a empresa irá  ganhar com a propaganda
*/
double myFor(int i, int repeticoes, double totalArrecadacao)
{
    // Verifica se o número de repeticoes é menor que i
    if (repeticoes < i)
    {
        // Cria um array de char para armazenar o tipo de mídia
        char midiaPropaganda[MAX_INT];

        // Solicita a entrada do tipo de mídia
        scanf("%s", midiaPropaganda);

        // Obtém o valor associado ao tipo de mídia usando a função mudaValorFinal
        double valorMidia = mudaValorFinal(midiaPropaganda);

        // Chama a função recursivamente, atualizando os valores e incrementando repeticoes
        return myFor(i, repeticoes + 1, totalArrecadacao + valorMidia);
    }

    // Retorna o valor total quando repeticoes for igual a i
    return totalArrecadacao;
}
/*
int main() {
    // Chama a função recursiva e imprime o resultado formatado
    printf("%.2lf", myFor(7, 0, 0));
    return 0;
}
*/
int main()
{
    double totalArrecadacao = 0;
    for (int i=0; i<7; i++)
    {
        // Cria um array de char para armazenar o tipo de mídia
        char midiaPropaganda[MAX_INT];

        // Solicita a entrada do tipo de mídia
        scanf("%s", midiaPropaganda);
        if (strcmp(midiaPropaganda, "Rádio") == 0)
        {
            char opcao[MAX_INT];
            scanf("%s", opcao);

            // Retorna o valor com base na opção escolhida
            if (strcmp(opcao, "AM") == 0)
            {
                totalArrecadacao += 300;
            }
            else
            {
                totalArrecadacao += 500;
            }
        }
        else if (strcmp(midiaPropaganda, "TV") == 0)
        {
            int horario;
            scanf("%d", &horario);

            // Retorna o valor com base no horário de exibição
            if (horario > 20)
            {
                totalArrecadacao += 2000;
            }
            else
            {
                totalArrecadacao += 1200;
            }
        }
        else if (strcmp(midiaPropaganda, "Revista") == 0)
        {
            // Retorna o valor fixo para a mídia Revista
            totalArrecadacao += 750;
        }
        else if (strcmp(midiaPropaganda, "Outdoor") == 0)
        {
            // Retorna o valor fixo para a mídia Outdoor
            totalArrecadacao += 1500;
        }
    }
    printf("%.2lf", totalArrecadacao);
    return 0;
}