#include <stdio.h>
int main() {
    int estudante, idoso;
    scanf("%d%d", &estudante,&idoso);
    printf("%d",estudante==1 || idoso==1?1:0);
	return 0;
}