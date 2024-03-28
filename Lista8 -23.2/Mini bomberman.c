#include <stdio.h>

void explodePosicao(int coordenadaX, int coordenadaY, int tamanho, char array[][tamanho]){
    if(array[coordenadaX][coordenadaY]=='#') return;
    else if(array[coordenadaX][coordenadaY]=='&') array[coordenadaX][coordenadaY]='_';
}

int main(){
    int tamanhoMatrizUm, alturaMatrizDois;
    scanf("%d", &tamanhoMatrizUm);
    char matrizUm[tamanhoMatrizUm][tamanhoMatrizUm];
    for(int i=0;i<tamanhoMatrizUm;i++){
        for(int d=0;d<tamanhoMatrizUm;d++){
            scanf(" %c", &matrizUm[i][d]);
        }
    }
    scanf("%d", &alturaMatrizDois);
    int matrizDois[alturaMatrizDois][2];
    for(int i=0;i<alturaMatrizDois;i++){
        for(int d=0;d<2;d++){
            scanf("%d", &matrizDois[i][d]);
        }
    }
    /*
    '#' são paredes inquebráveis;
    '_' caminhos vazios;
    '&' paredes quebráveis.
    */
    for(int i=0;i<alturaMatrizDois;i++){
        /*
        •⁠  ⁠o segundo array sempre vai ser Mx2
        •⁠  ⁠⁠você vai verificar sempre se matrizUm[matrizDois[posicao do teu loop][matrizDois[0]] é igual a _ (ele precisa ser obrigatoriamente igual a _
        */
            if(matrizUm[matrizDois[i][0]][matrizDois[i][1]]=='_'){
                //Explode em cima
                if(matrizDois[i][0]-1<0) explodePosicao(tamanhoMatrizUm-1, matrizDois[i][1], tamanhoMatrizUm, matrizUm);
                else explodePosicao(matrizDois[i][0]-1, matrizDois[i][1], tamanhoMatrizUm, matrizUm);
                //Explode em baixo
                if(matrizDois[i][0]+1==tamanhoMatrizUm) explodePosicao(0, matrizDois[i][1], tamanhoMatrizUm, matrizUm);
                else explodePosicao(matrizDois[i][0]+1, matrizDois[i][1], tamanhoMatrizUm, matrizUm);
                //Expldoe direita                
                if(matrizDois[i][1]+1==tamanhoMatrizUm) explodePosicao(matrizDois[i][0], 0, tamanhoMatrizUm, matrizUm);
                else explodePosicao(matrizDois[i][0], matrizDois[i][1]+1, tamanhoMatrizUm, matrizUm);
                //Explode a esquerda
                if(matrizDois[i][1]-1<0) explodePosicao(matrizDois[i][0], tamanhoMatrizUm-1,tamanhoMatrizUm,  matrizUm);
                else explodePosicao(matrizDois[i][0], matrizDois[i][1]-1, tamanhoMatrizUm, matrizUm);
        }
    }
    int i, d;
    for(i=0;i<tamanhoMatrizUm;i++){
        for(d=0;d<tamanhoMatrizUm;d++){
            printf("%c", matrizUm[i][d]);
        }
        printf("\n");
    }
    return 0;
}