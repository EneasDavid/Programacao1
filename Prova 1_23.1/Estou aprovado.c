#include <stdio.h>

//Eneas e pika o resto e buraco

int main() {
    int idade;
    double notaUm, notaDois, notaTres, media;
    scanf("%d %lf %lf %lf", &idade, &notaUm,&notaDois,&notaTres);
    if(notaUm<4 || notaDois<4 || notaTres<4){
        printf("Reprovado");
    }else{
        if(idade>=18){
            media=((notaUm*6)+(notaDois*6)+notaTres)/15;
        }else{
            if (notaUm < 7 && notaUm > notaDois) {
                media = (notaDois + notaTres) / 2;
            } else if (notaDois < 7 && notaDois > notaUm) {
                media = (notaUm + notaTres) / 2;
            } else {
                media = (notaUm + notaDois) / 2;
            }
        }
        if(media>=5.5){
            printf("Aprovado");
        }else{
            printf("Reprovado");
        }
    }
    return 0;
}