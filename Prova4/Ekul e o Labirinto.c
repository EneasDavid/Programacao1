#include <stdio.h>

int dragoonPresent(int x, int y, int N, int maze[N][N]) {
    for (int i=x-1; i<=x+1; i++) {
        for (int j=y-1; j<=y+1; j++) {
            if (i>=0 && i<N && j>=0 && j<N && maze[i][j]==2) return 1;
        }
    }
    return 0;
}

int canEscape(int x, int y, int N, int maze[N][N]) {
    if (x<0 || x>=N || y<0 || y>=N) return 0;
    if (dragoonPresent(x, y, N, maze)) return 0;
    if (x==N-1 && y== N-1) return 1;
    if (maze[x][y]==0 || maze[x][y]==3) return 0;

    maze[x][y]=3;

    int dx[2]={1, 0};
    int dy[2]={0, 1};
    for (int i=0; i<2; i++) {
        int nextX=x+dx[i];
        int nextY=y+dy[i];
        if (canEscape(nextX, nextY, N, maze)) return 1;
    }
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    int mapaLabirinto[N][N];
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &mapaLabirinto[i][j]);
        }
    }
    if (canEscape(0, 0, N, mapaLabirinto)) printf("Ekul conseguiu ludibriar a dragoa!\n");
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