#include <stdio.h>
int main() {
    int alunos, livros;
    scanf("%d%d", &livros, &alunos);
    int qtnL=alunos/livros;
    if(qtnL<=8){
        printf("A");
    }else if(qtnL<=12){
        printf("B");
    }else if(qtnL<=18){
        printf("C");
    }else{
        printf("D");
    }
	return 0;
}