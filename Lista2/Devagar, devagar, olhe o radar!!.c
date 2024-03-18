#include <stdio.h>
int main() {
    int velocidade, vPermitida;
    scanf("%d%d", &vPermitida, &velocidade);
    if (velocidade <= vPermitida) {
        printf("0.00\n0");
    } else if (velocidade <= vPermitida * 1.2) {
        printf("85.13\n4");
    } else if (velocidade <= vPermitida * 1.5) {
        printf("127.69\n5");
    } else {
        printf("574.62\n7");
    }
	return 0;
}