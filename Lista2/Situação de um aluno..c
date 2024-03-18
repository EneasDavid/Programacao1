#include <stdio.h>
int main() {
    int um, dois,tres;
    scanf("%d %d %d",&um, &dois, &tres);
    if(um==-1 || dois==-1 || tres==-1){
        printf("Media invalida");
    }else{
        char* status;
        double media=(double)(um+dois+tres)/3;
        if(media>=70){
            status="APROVADO";
        }else if(media>0 && media<=40){
            status="REPROVADO";
        }else{
            status="FINAL";
        }
        printf("A media do aluno foi %.2f e ele foi %s\n", media, status);
    }
	return 0;
}