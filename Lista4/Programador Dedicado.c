#include <stdio.h>
#include <string.h>
void recebeEntradas(int diaSemana, int metaCods, int metaLinhas, int maximo, char melhorDia[15]) {
    int codigos, linhas;
    if (diaSemana--) {
        scanf("%d %d", &codigos, &linhas);
        if (codigos>=5) {
            metaCods++;
        }
        if (linhas>=100) {
            metaLinhas++;
        }
        if (linhas*codigos>=maximo) {
            maximo=linhas*codigos;
            if(diaSemana==6){
                strcpy(melhorDia,"DOMINGO");
            }else if(diaSemana==5){
                strcpy(melhorDia,"SEGUNDA");
            }else if(diaSemana==4){
                strcpy(melhorDia,"TERCA");
            }else if(diaSemana==3){
                strcpy(melhorDia,"QUARTA");
            }else if(diaSemana==2){
                strcpy(melhorDia,"QUINTA");
            }else if(diaSemana==1){
                strcpy(melhorDia,"SEXTA");
            }else if(diaSemana==0){
                strcpy(melhorDia,"SABADO");
            }
        }
        recebeEntradas(diaSemana, metaCods, metaLinhas, maximo, melhorDia);
    }else{
        printf("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE PROGRAMAS: %d\nQUANTIDADE DE DIAS QUE ATINGIU MEDIA DE LINHAS: %d\nDIA QUE MAIS PRODUZIU: %s\n", metaCods, metaLinhas, melhorDia);
    }
}

int main() {
    char melhorDia[15] = "";
    recebeEntradas(7, 0, 0, 0, melhorDia);
    return 0;
}