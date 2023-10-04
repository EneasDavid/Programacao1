#include <stdio.h>
#include <string.h>

void esquemaParede(int i, int j, int n, int m, int mapa[][m], char posicao[], int comecoX, int comecoY, int qtd){
	if (i<qtd){
		if (posicao[i]=='C'){
			if (comecoX<n && comecoX-1>=0){
				if (mapa[comecoX-1][comecoY]==1){
					comecoX-=1;
				}
			}

		}
		else if(posicao[i]=='B'){
			if(comecoX+1<n && comecoX>=0){
				if(mapa[comecoX+1][comecoY]==1){
					comecoX+=1;
				}
			}
		}
		else if(posicao[i]=='E'){
			if(comecoY<m && comecoY-1>=0){
				if(mapa[comecoX][comecoY-1]==1){
					comecoY-=1;
				}
			}
		}
		else if(posicao[i]=='D'){
			if(comecoY+1<m && comecoY>=0){
				if (mapa[comecoX][comecoY+1]==1){
					comecoY+=1;
				}
			}
		}
		esquemaParede(++i, j, n, m, mapa, posicao, comecoX, comecoY, qtd);
	}
	else{
		printf("(%d,%d)\n", comecoX, comecoY);
	}

}

void jogadas(int i, int n, int m, int mapa[][m],char posicao[], int qtd, int comecoX, int comecoY){
	if(i<qtd){
		scanf(" %c", &posicao[i]);
		jogadas(i+1, n, m, mapa, posicao, qtd, comecoX, comecoY);
	}else{
		scanf("%d%d", &comecoX, &comecoY);
		esquemaParede(0, 0, n, m, mapa, posicao, comecoX, comecoY, qtd);
	}
}

void play(int i, int j, int n, int m, int mapa[][m]){
	if(i<n){
		if(j<m){
			scanf("%d", &mapa[i][j]);
			play(i, ++j, n, m, mapa);
		}
		else play(++i, 0, n, m, mapa);
	}
}

int main(){
	int n,m;
	scanf("%d\n%d", &n, &m);
	int mapa[n][m];
	play(0, 0, n, m, mapa);
	int qtd, comecoX = 0, comecoY = 0;
	scanf("%d", &qtd);
	char posicao[qtd];
	jogadas(0, n, m, mapa, posicao, qtd, comecoX, comecoY);
	return 0;
}