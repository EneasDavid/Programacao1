#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    double i, d;
    scanf("%lf%lf", &i, &d);
    printf("%.2f",i*.3-d<0?0.00:i*.3-d);
	return 0;
}