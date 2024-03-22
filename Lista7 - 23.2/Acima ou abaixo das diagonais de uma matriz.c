#include <stdio.h>

int main(){
    char lado[6];
    int limiar, tamanhoMatriz, total=0;
    scanf("%[^\n]", lado);
    if(strcmp(lado, "acima")==0){
        for(int i=0;i<tamanhoMatriz;i++){
            for(int d=0;d<tamanhoMatriz;d++){
                int entrada;
                printf("%d ", i<d);
                scanf("%d", &entrada);
                if(i>d){
                    total+=entrada;
                }
            }
            printf("\n");
        }    
    }else{
        for(int i=0;i<tamanhoMatriz;i++){
            for(int d=0;d<tamanhoMatriz;d++){
                int entrada;
                scanf("%d", &entrada);
                printf("%d ", i<d);
                if(i<d){
                    total+=entrada;
                }
            }
                        printf("\n");
        }
    }
    if(total>=limiar) printf("True\n");
    else printf("False\n");
    return 0;
}
// scanf("%[^\n]")