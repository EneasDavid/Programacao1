#include <stdio.h>

int dragoaPresente(int x, int y, int N, int labirinto[N][N]) {
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < N && j >= 0 && j < N && labirinto[i][j] == 2) return 1;
        }
    }
    return 0;
}

int podeEscaparLabirinto(int x, int y, int N, int labirinto[N][N]) {
    if (x < 0 || x >= N || y < 0 || y >= N) return 0;
    if (x == N - 1 && y == N - 1) return 1;
    if (labirinto[x][y] == 0 || labirinto[x][y] == 3) return 0;
    labirinto[x][y] = 3;

    if (explorarCaminho(x + 1, y, N, labirinto) || explorarCaminho(x, y + 1, N, labirinto)) return 1;
    return 0;
}

int explorarCaminho(int x, int y, int N, int labirinto[N][N]) {
    if (dragoaPresente(x, y, N, labirinto)) return 0;
    return podeEscaparLabirinto(x, y, N, labirinto);
}

int main() {
    int N;
    scanf("%d", &N);
    int labirinto[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &labirinto[i][j]);
        }
    }
    if (podeEscaparLabirinto(0, 0, N, labirinto)) printf("Ekul conseguiu ludibriar a dragoa!\n");
    else printf("Ekul tomou o nhac da dragoa :(\n");
    return 0;
}
/*
[|] [0] [0]
    
[|] [0] [*]
    
[|] [0] [0]
    
[|] [-] [-]
*/
    
    
/*
Teste
4
2 0 1 1
0 0 1 1
1 1 1 1
1 1 1 1

4
0 0 1 1
0 0 1 1
1 1 1 1
1 1 1 1

4
1 1 1 0
1 2 1 1
1 1 1 1
1 1 1 1


4
1 1 1 0
0 0 0 1
0 2 0 1
0 0 0 1

4
1 1 1 0
0 0 0 1
0 2 0 1
1 0 0 1


10
1 1 1 0 0 1 1 1 0 0
0 0 1 0 1 0 0 0 1 1
0 1 0 1 1 1 0 1 0 0
0 0 1 0 0 0 0 1 1 0
1 1 1 0 1 0 1 1 0 1
0 1 0 0 1 1 1 1 0 1
1 1 0 1 1 0 0 0 1 1
1 1 0 1 1 0 1 1 0 0
0 0 0 1 1 0 0 1 0 1
1 1 1 1 0 1 0 1 1 1

*/