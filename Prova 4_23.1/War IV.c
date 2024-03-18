#include<stdio.h>

int main(){
    int N ,M, A, x,y,D;
    scanf("%d%d",&N,&M);
    int tabuleiro[N][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d", &tabuleiro[i][j]);
        }
    }
    scanf("%d", &A);
    for(int k=0;k<A;k++){
    scanf("%d%d%d", &x,&y,&D);
    for(int i=x-1;i<=x+1;i++){
        for(int j=y-1;j<=y+1;j++){
            if(i>=0&&i<N&&j>=0&&j<M){
                int dano=D;
                if(i!=x||j!=y){
                    dano/=2;
                }
                    if(tabuleiro[i][j]-dano<0){
                        tabuleiro[i][j]=0;
                    }else{
                        tabuleiro[i][j]-=dano;
                    }
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%d",tabuleiro[i][j]);
            if(j<M-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}