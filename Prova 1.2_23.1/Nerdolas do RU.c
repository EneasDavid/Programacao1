#include <stdio.h>
#include <string.h>
int calc(char x, int a, int b, int c, int d, int e, int i, int j, int k, int l, int m) {
    if (x == 'a') return a;
    else if (x == 'b') return b;
    else if (x == 'c') return c;
    else if (x == 'd') return d;
    else if (x == 'e') return e;
    else if (x == 'i') return i;
    else if (x == 'j') return j;
    else if (x == 'k') return k;
    else if (x == 'l') return l;
    else if (x == 'm') return m;
}
int backToStart(int x) {
    return x % 100;
}
int main() {
    char lUmR, lDoisR, lUmF, lDoisF, lUmRu, lDoisRu, lUmH, lDoisH;
    int vA, vB, vC, vD, vE, vI, vJ, vK, vL, vM, ryan, filipe, ruan, heron;
    scanf("%c %c %c %c %c %c %c %c %d %d %d %d %d %d %d %d %d %d", &lUmR, &lUmF, &lUmRu, &lUmH, &lDoisR, &lDoisF, &lDoisRu, &lDoisH, &vA, &vB, &vC, &vD, &vE, &vI, &vJ, &vK, &vL, &vM);
    ryan = backToStart(calc(lUmR, vA, vB, vC, vD, vE, vI, vJ, vK, vL, vM) * calc(lDoisR, vA, vB, vC, vD, vE, vI, vJ, vK, vL, vM));
    filipe = backToStart(calc(lUmF, vA, vB, vC, vD, vE, vI, vJ, vK, vL, vM) * calc(lDoisF, vA, vB, vC, vD, vE, vI, vJ, vK, vL, vM));
    ruan = backToStart(calc(lUmRu, vA, vB, vC, vD, vE, vI, vJ, vK, vL, vM) * calc(lDoisRu, vA, vB, vC, vD, vE, vI, vJ, vK, vL, vM));
    heron = backToStart(calc(lUmH, vA, vB, vC, vD, vE, vI, vJ, vK, vL, vM) * calc(lDoisH, vA, vB, vC, vD, vE, vI, vJ, vK, vL, vM));
    if (ryan != filipe && ryan != ruan && ryan != heron && filipe != ruan && filipe != heron && ruan != heron) {
        int max = ryan, min = heron;
        char nCampeao[10] = "Ryan", nPerdedor[10] = "Heron";
        if (max < filipe) {
            strcpy(nCampeao, "Filipe");
            max = filipe;
        }
        if (max < ruan) {
            strcpy(nCampeao, "Ruan");
            max = ruan;
        }
        if (max < heron) {
            strcpy(nCampeao, "Heron");
            max = heron;
        }
        if (min > filipe) {
            strcpy(nPerdedor, "Filipe");
            min = filipe;
        }
        if (min > ruan) {
            strcpy(nPerdedor, "Ruan");
            min = ruan;
        }
        if (min > ryan) {
            strcpy(nPerdedor, "Ryan");
            min = ryan;
        }
        printf("%s %d - Vencedor\n%s %d - Perdedor", nCampeao, max, nPerdedor, min);
    }
    return 0;
}