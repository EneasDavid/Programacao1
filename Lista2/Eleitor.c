#include <stdio.h>

int main() {
    int idade;
    scanf("%d", &idade);
    if(idade<=16){
        printf("nao eleitor");
    }else if(idade>=18 && idade<=65){
        printf("eleitor obrigatorio");
    }else{
        printf("eleitor facultativo");
    }
	return 0;
}