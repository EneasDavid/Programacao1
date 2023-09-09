int batalha(int v1, int v2, int d1, int d2) {
    if (v1 <= 0) {
        return 0;
    } else if (v2 <= 0) {
        return 1;
    }
    if (ceil((double)v1 / d2) < ceil((double)v2 / d1)) {
        d1 += 50;
    } else {
        v2 -= d1;
    }
    if (v2 > 0) {
        v1 -= d2;  
    }
    return batalha(v1, v2, d1, d2);
}
pokemon(int n) {
    if (n--) {
        int v1, v2, d1, d2;
        scanf("%d%d%d%d", &v1, &v2, &d1, &d2);
        int saida = batalha(v1, v2, d1, d2);
        if (saida) {
            printf("Clodes\n");
        } else {
            printf("Bezaliel\n");
        }
        return pokemon(n);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    pokemon(n);
    return 0;
}
