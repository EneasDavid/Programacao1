#include <stdio.h>

int batalha(int nivelM, int cont, int arrayInimigos[], int qtnInimigos, int qtnVitorias){
    if(cont==qtnInimigos){
        printf("Nível de energia: %d\n%.2lf%%\n", nivelM, ((double)qtnVitorias/qtnInimigos)*100);
        return nivelM;
    }
    if (arrayInimigos[cont]>nivelM) return batalha(nivelM, cont+1, arrayInimigos, qtnInimigos, qtnVitorias);
    return batalha(nivelM+(nivelM-arrayInimigos[cont]), cont+1, arrayInimigos, qtnInimigos, qtnVitorias+1);
}

void myWhile(int contador, int inimigosOrdenados[], int inimigos[]){
    if(contador<0) return;
    myWhile(contador-1, inimigosOrdenados, inimigos);
    int valor;
    scanf("%d", &valor);
    inimigosOrdenados[contador]=inimigos[valor-1];
}

void myFor(int contador, int inimigos[]){
    if(contador<0) return;
    myFor(contador-1, inimigos);
    scanf("%d", &inimigos[contador]);
}

int main(){
    int nivelMarquinhos, qtnInimigos;
    scanf("%d%d", &nivelMarquinhos, &qtnInimigos);
    int inimigos[qtnInimigos], inimigosOrdenados[qtnInimigos];
    myFor(qtnInimigos-1, inimigos);
    myWhile(qtnInimigos-1, inimigosOrdenados, inimigos);
    if(batalha(nivelMarquinhos, 0, inimigosOrdenados, qtnInimigos,0)<20000) printf("Continue tentando!");
    else printf("Marquinhos é o novo Mestre da Vila da Árvore!");
    return 0;
}