#include <stdio.h>

void descontoJogo(double *precoJogo, int dificuldadeJogo){
    if(*precoJogo>45){
        switch(dificuldadeJogo){
            case 0:
                *precoJogo*=*precoJogo<=100?.875:.75;
                break;
            case 1:
                *precoJogo*=*precoJogo<=100?.90:.80;
                break;
            case 2:
                *precoJogo*=*precoJogo<=100?.91:.82;
                break;
            case 3:
                *precoJogo*=*precoJogo<=100?.925:.85;
                break;
            case 4:
                *precoJogo*=*precoJogo<=100?.94:.88;
                break;
            case 5:
                *precoJogo*=*precoJogo<=100?.95:.90;
                break;
        }
        if(*precoJogo<45){
            *precoJogo=45;
        }
    }
    return;
}
void myFor(int loop, double *precoJogo, int dificuldadeJogo){
    if(loop>0){
        descontoJogo(precoJogo, dificuldadeJogo);
        myFor(loop-1, precoJogo, dificuldadeJogo);
    }
}
void myWhile(int loop, int posicao){
    int dificuldade; 
    double  preco, *ponteiroPreco=&preco;
    if(loop!=0){
        scanf("%d %lf", &dificuldade, ponteiroPreco);
        myFor(3, ponteiroPreco, dificuldade);
        printf("Jogo[%d] = R$%.2lf\n", posicao, preco);
        myWhile(loop-1, posicao+1);
    }
    return;
}

int main(){
    int qtnEntrada;
    scanf("%d", &qtnEntrada);
    myWhile(qtnEntrada,0);
    return 0;
}
