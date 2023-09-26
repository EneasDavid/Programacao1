#include <stdio.h>
#include <string.h> // Inclua esta biblioteca para usar strtok

int main() {
    int qtnRep; 
    scanf("%d", &qtnRep);
    double totalPeso = 0.0;
    double totalvalor = 0.0;

    for (int teste = 1; teste <= qtnRep; teste++) {
        double valorGasto;
        scanf("%lf", &valorGasto);

        char frutas[1000];
        getchar(); 
        fgets(frutas, sizeof(frutas), stdin);

        double pesoDia = 0.0;
        char *fruta = strtok(frutas, " \n"); 

        printf("dia %d:", teste);

        while (fruta != NULL) {
            pesoDia++; 
            printf(" %s", fruta);
            fruta = strtok(NULL, " \n");
        }

        totalPeso += pesoDia;
        totalvalor += valorGasto;

        printf("\n");
    }

    double mediaPeso = totalPeso / qtnRep;
    double mediavalorGastoalor = totalvalor / qtnRep;

    printf("%.2lf kg por dia\nR$ %.2lf por dia\n", mediaPeso, mediavalorGastoalor);

    return 0;
}
