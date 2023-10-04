#include <stdio.h>

int fabricaInteio(int n, int todasAposta[n][10], int resultado[6], int indice, int vencedores) {
    if (indice==n) return vencedores;
    else{
        int contador=0;
        for(int atual=0; atual<10; atual++){
            for(int indice_result=0; indice_result<6; indice_result++){
                if(todasAposta[indice][atual]==resultado[indice_result]) contador++;
            }
        }
        if(contador==6) vencedores++;
        return fabricaInteio(n, todasAposta, resultado, indice + 1, vencedores);
    }
}
int main() {
    int apostas;
    scanf("%d", &apostas);
    int todasAposta[apostas][10];
    for(int i=0; i<apostas; i++){
        for(int j=0; j<10; j++){
            int temporario;
            if (scanf("%d", &temporario)!=EOF) todasAposta[i][j]=temporario;
            char caract=getchar();
            if (caract=='\n') break;
        }
    }
    int resultado[6];
    for(int x=0; x<6; x++) scanf("%d", &resultado[x]);
    int a=fabricaInteio(apostas, todasAposta, resultado, 0, 0);
    printf("Total de ganhadores: %d\n", a);
}