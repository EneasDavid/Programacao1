#include <stdio.h>

int verificarSudoku(int mat[9][9]){
    int nums[]={1,2,3,4,5,6,7,8,9};
    int valido=1;
    for (int i=0; i<9; i++){
        int linha[9], coluna[9];
        for (int j=0; j<9; j++){
            linha[j]=mat[i][j];
            coluna[j]=mat[j][i];
        }
        for (int k=0; k<9; k++){
            for (int l=k+1; l<9; l++){
                if (linha[k]==linha[l] || coluna[k]==coluna[l]){
                    valido=0;
                    break;
                }
            }
        }
    }
    for(int i=0; i<9; i+=3){
        for(int j=0; j<9; j+=3){
            int submatriz[9];
            int index=0;
            for(int k=i; k<i+3; k++){
                for(int l=j; l<j+3; l++){
                    submatriz[index++]=mat[k][l];
                }
            }
            for(int m=0; m<9; m++){
                for(int n=m+1; n<9; n++){
                    if(submatriz[m]==submatriz[n]){
                        valido=0;
                        break;
                    }
                }
            }
        }
    }
    return valido;
}

int main(){
    int k;
    scanf("%d", &k);
    for (int i=0; i<k; i++){
        int mat[9][9];
        for (int j=0; j<9; j++){
            for (int l=0; l<9; l++){
                scanf("%d", &mat[j][l]);
            }
        }
        int resultado=verificarSudoku(mat);
        if (resultado) printf("Instancia %d\nSIM\n\n", i+1);
        else printf("Instancia %d\nNAO\n\n", i+1);
    }
    return 0;
}
