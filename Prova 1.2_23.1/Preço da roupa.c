#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void calc(double x, double y, double z){
    printf("%.2f R$",((x * y + x * z) / 2));
}
int main() {
    double cMaterial, tamanhoP, tipoP;
    char tamanho, tipoR;
    scanf("%lf\n%c\n%c", &cMaterial, &tamanho, &tipoR);
    switch(tipoR){
        case 'B':
            tipoP=3.82;
            break;
        case 'C':
            tipoP=4.55;
            break;
        case 'M':
            tipoP=7.12;
            break;
            
    }
    switch(tamanho){
        case 'P':
            tamanhoP=2.75;
            break;
        case 'M':
            tamanhoP=3.66;
            break;
        case 'G':
            tamanhoP=5.17;
            break;
            
    }
    calc(cMaterial, tamanhoP, tipoP);
	return 0;
}