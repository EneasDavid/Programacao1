#include <stdio.h>

int main() {
    double r;
    scanf("%lf", &r);

    double area = 3.14159 * r * r / 10000.0;

    printf("Area = %.4lf\n", area);

    return 0;
}