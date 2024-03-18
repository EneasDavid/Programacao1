#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    double num;
    scanf("%lf", &num);
    printf("%.2lf", (num*0.1)+num);
	return 0;
}