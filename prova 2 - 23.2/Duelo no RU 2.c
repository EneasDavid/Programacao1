#include <stdio.h>

int mudaAtaque(int ataque, int bonus){
    return ataque+bonus;
}

int mudaVida(int vida, int bonus){
    return vida+bonus;
}

int Fibonacci(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return Fibonacci(n-1)+Fibonacci(n-2);
}

int myWhile2(int qtnAmigos, int ekulVida, int ekulAtaque){
    int confianca;
    char estaComFome;
    if(!qtnAmigos) return;
    scanf("%d %c", &confianca, &estaComFome);
    if(estaComFome == 'F' && Fibonacci(confianca)){
        mudaVida(ekulVida, confianca%100);
        mudaAtaque(ekulAtaque, (confianca%100)/2);
    }
    myWhile2(qtnAmigos-1, ekulVida, ekulAtaque);
}

void myWhile( int rounds){
    int ekulVida, ekulAtaque, lukeVida, lukeAtaque, qtnAmigos;
    if(rounds) return;
    scanf("%d%d%d%d%d", &ekulVida, &ekulAtaque, &lukeVida, &lukeAtaque, &qtnAmigos);
    myWhile2(qtnAmigos, ekulVida, ekulAtaque);
    
    if(ekulVida>lukeVida){
        printf("Ekul\n");
    }else{
        printf("Luke\n");
    }
}
int main(){
    int rounds;
    scanf("%d", &rounds);
    myWhile;
    return 0;
}