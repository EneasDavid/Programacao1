#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {
    char gradTres[5][10];
    int tempo[5][10];
     for(int i=0; i<5; i++) {
        for(int d=0; d<10; d++) {
            scanf(" %c", &gradTres[i][d]);
        }
    }
    int menorTempo=INT_MAX;
    int melhorX=-1, melhorY=-1;
    for(int i=0; i<5; i++) {
        for(int d=0; d<10; d++) {
            if(gradTres[i][d]=='*') tempo[i][d]=-1;
            else {
                int distancia=sqrt(pow(i, 2)+pow(d, 2));
                tempo[i][d]=(gradTres[i][d]=='0')?(distancia*20)+40:distancia*20;
                if(tempo[i][d]<menorTempo) {
                    menorTempo=tempo[i][d];
                    melhorX=d;
                    melhorY=i;
                }
            }
        }
    }

    if(menorTempo==INT_MAX) printf("Tristemente voce vai ter que aturar os PCs do grad 4\n");
    else printf("Vai la pro computador %d da fileira %d\n", melhorX, melhorY);

    return 0;
}
