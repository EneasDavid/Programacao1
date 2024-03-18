#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, delta;
    scanf("%f %f %f", &a, &b, &c);
    delta = pow(b, 2) - 4 * a * c;
    if (a != 0) {
        if (delta < 0) {
            printf("NRR\n");
        } else {
            printf("%.2f\n", (-b + sqrt(delta)) / (2 * a));
            printf("%.2f\n", (-b - sqrt(delta)) / (2 * a));
        }
    } else {
        printf("NEESG\n");
    }
    return 0;
}