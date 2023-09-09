#include <stdio.h>
#include <math.h>

int main(){
    double a, b, c, delta;
    scanf("%lf %lf %lf", &a, &b, &c);
    delta = pow(b, 2) - 4 * a * c;
    if (a != 0) {
        if (delta >= -0.000001){
            delta = fabs(delta);
            printf("%.2lf\n", (-b + sqrt(delta)) / (2 * a));
            printf("%.2lf\n", (-b - sqrt(delta)) / (2 * a));
        }
    }
    return 0;
}