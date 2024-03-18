#include <stdio.h>

int main() {
    char sexo, nacionalidade, maiorIdade=0;
    int idade;
    double desconto=1, preco;
    scanf("%c %d %c %lf", &nacionalidade,&idade,&sexo, &preco);
   
    if(nacionalidade=='B' || nacionalidade=='A'){
        if(idade>=18){
            maiorIdade=1;
        }
    }else if(nacionalidade=='F' || nacionalidade=='C'){
        if(idade>=21){
            maiorIdade=1;
        }
    }else{
        if(idade>=16){
            maiorIdade=1;
        }
    }
    
    if(idade<=0 || idade>120){
        printf("idade invalida!");
    }else{
        if(sexo=='F'){
                desconto=0.9;
            }
        if(nacionalidade=='B'){
            desconto=0.5;
        }
        if(nacionalidade=='A'){
            if(!maiorIdade){
                desconto=0.8;
            }else if(sexo=='F'){
                desconto=0.8;
            }
        }
        if(nacionalidade=='F' || nacionalidade=='C'){
            if(!maiorIdade){
                printf("nao pode comprar");
                return 0;
            }else if(maiorIdade){
                desconto=0.7;                
            }
        }
        if(nacionalidade=='I' || nacionalidade=='R'){
            if(maiorIdade){
                desconto=0.7;
            }else{
                desconto=0.6;
            }
        }
        printf("R$ %.2f",preco*desconto);
    }
	return 0;
}

/*

Regras para o desconto (verificar a legisla??o e o desconto aplicado ser? o maior, ou seja, n?o ? cumulativo):

Se o sexo for feminino, 10% de desconto independente da nacionalidade.
Se for Brasileiro, desconto de 50% independente do sexo e da idade.
Se for Argentino (masculino) com maioridade legal, n?o tem desconto.
Se for Argentina (feminino) com maioridade legal, desconto de 20%.
Se for Argentino (masculino ou feminino) menor, desconto de 20%.
Se for Franc?s ou Croata com maioridade legal, desconto de 30%.
Se for Italiano ou Russo (masculino ou feminino) menor, desconto de 40%.
Se for Italiano ou Russo (masculino ou feminino) com maioridade legal, desconto de 30%.




DEVE SER APLICADO O MAIOR DESCONTO! 

Por exemplo, Russa (feminino) com maioridade legal deve ter 30% de desconto e n?o 10% (caso inicial).

*/