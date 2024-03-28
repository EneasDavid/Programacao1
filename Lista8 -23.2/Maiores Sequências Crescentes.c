#include <stdio.h>

int main() {
    int largura, altura;
    scanf("%d %d", &altura, &largura);
    int matriz[altura][largura], maioresSequencias[altura];
    for(int i=0;i<altura;i++){
        for(int d=0;d<largura;d++){
            scanf("%d", &matriz[i][d]);
        }
    }
    for (int i=0; i<altura; i++) {
        int rep=1;
        int maxRep=1; 
        for(int d=0;d<largura-1;d++){
            if(matriz[i][d]<=matriz[i][d+1]){
                rep++;
                if(rep>maxRep) maxRep=rep;
            }else rep=1;
        }
        maioresSequencias[i]=maxRep;
        printf("Linha %d: %d\n", i, maioresSequencias[i]); 
    }
    for(int i=0;i<altura;i++){
           if(maioresSequencias[i]>maioresSequencias[i+1] && i+1<altura){
            maioresSequencias[i]=maioresSequencias[i]^maioresSequencias[i+1];
            maioresSequencias[i+1]=maioresSequencias[i+1]^maioresSequencias[i];
            maioresSequencias[i]=maioresSequencias[i]^maioresSequencias[i+1];
        }
    }
    printf("Maior Sequencia: %d\n", maioresSequencias[altura-1]);
    return 0;
}
