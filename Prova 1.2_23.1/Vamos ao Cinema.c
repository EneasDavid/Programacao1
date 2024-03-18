#include <stdio.h>
int main() {
    
    int qtnAlunoTotal, qtnSupC, onibus, cp, onibusCheio, vagasCheias, assentos;
    scanf("%d%d%d%d", &qtnAlunoTotal, &qtnSupC, &onibus, &cp);
    
    if(qtnAlunoTotal!=0){
        if(qtnSupC>0){
            qtnAlunoTotal+=qtnAlunoTotal%qtnSupC>0?(qtnAlunoTotal/qtnSupC)+1:qtnAlunoTotal/qtnSupC;
        }
        assentos=((onibus*cp)-qtnAlunoTotal);
        if(assentos>=0){
            printf("Iremos ao cinema!\n");
            printf(assentos==0?"Todas as vagas foram preenchidas.":"Vagas Vazias = %d",assentos);
        }else{
            printf("N�o � poss�vel.\nFalta %d vagas.",assentos*-1);
        }
    
        
    }else{
        printf("Davi foi assistir o filme sozinho =(");
    }
	return 0;
}