#include <stdio.h>
int mdc(int x, int y) {
    int resto = x % y;
    if(resto==0) {
        return y;
    } else {
        return mdc(y, resto);
    }
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", mdc(x, y));
    return 0;
}