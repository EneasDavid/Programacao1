#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int num, h;
    double s;
    scanf("%d %d %lf", &num, &h, &s);
    printf("NUMBER = %d\nSALARY = R$ %.2f", num, (h * s));
	return 0;
}