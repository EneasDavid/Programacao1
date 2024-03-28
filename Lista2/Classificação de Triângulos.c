#include <stdio.h>
int main() {
    int ladoUm, ladoDois, ladoTres;
    scanf("%d%d%d",&ladoUm, &ladoDois, &ladoTres);
    printf("%s\n",ladoUm==ladoDois && ladoDois==ladoTres?"equilatero":ladoUm!=ladoDois && ladoUm!=ladoTres && ladoDois!=ladoTres?"escaleno":"isosceles");
	return 0;
}