#include <stdio.h>
void calcP(int potencia){
    if(potencia<=20) printf("Potencia de : %d W",20 + (potencia*potencia*potencia));
    else if(potencia<=40) printf("Potencia de : %d W",8000 + ((potencia - 10)*(potencia - 10)));
    else if(potencia<=60) printf("Potencia de : %d W",9000 + 5*potencia);
    else if(potencia<=80) printf("Potencia de : %d W",9300 + 2*potencia);
    else printf("Potencia de : %d W",9500 + potencia);
}

int main() {
    int p;
    scanf("%d", &p);
    calcP(p);
    return 0;
}