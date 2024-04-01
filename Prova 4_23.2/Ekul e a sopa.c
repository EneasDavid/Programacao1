#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    float preco;
    int qtn;
    int disponivel;
} Produto;

int main() {
    int qtnProdutos;
    scanf("%d", &qtnProdutos);
    float soma=0;
    Produto produtos[qtnProdutos];
    for(int i=0; i<qtnProdutos; i++) {
        scanf("%s %f %d", produtos[i].nome, &produtos[i].preco, &produtos[i].qtn);
        produtos[i].disponivel=produtos[i].qtn>0;
    }
    int qtnPedidos;
    scanf("%d", &qtnPedidos);
    for(int i=0; i<qtnPedidos; i++) {
        char pedido[100];
        scanf("%s", pedido);
        for(int d=0; d<qtnProdutos; d++) {
            if(strcmp(pedido, produtos[d].nome)==0) {
                if(produtos[d].disponivel) {
                    produtos[d].qtn--;
                    produtos[d].disponivel=produtos[d].qtn>0;
                    soma+=produtos[d].preco;
                }
                break;
            }
        }
    }
    printf("A sopa custou R$ %.2f. Melhoras Ekul :(\n", soma);
    return 0;
}
