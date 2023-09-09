#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char um, dois, tres, quatro;
    scanf("%c %c %c %c", &um,&dois,&tres,&quatro);
    if(um=='E'){
        if(tres=='E'){
            printf("Galpao de ordenha");
        }
        else{
            printf("Estabulo");
        }
    }else if(dois=='E'){
        printf("Coucho");
    }else if(quatro=='E'){
        printf("Abrigo");
    }else if(quatro=='D'){
        printf("Pasto");
    }
	return 0;
}

