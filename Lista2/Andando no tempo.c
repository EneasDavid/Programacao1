#include <stdio.h>

int vTempo(int a, int b, int c) {
    if (a==b){
        c=0;
    }else if (b==c){
        a=0;
    }else if(c==a){
        b=0;
    }
     if(!(a-(b+c))){   
        return 1;
    }else if (!(b-(a+c))){
        return 1;
    }else if (!(c-(a+b))){
        return 1;
    }else{
        return 0;
    }
    return 0;
}

int main() {
    int creditoA, creditoB, creditoC;
    scanf("%d %d %d", &creditoA, &creditoB, &creditoC);

    if (vTempo(creditoA, creditoB, creditoC)){
        printf("S\n");
    }else{
        printf("N\n");
    }
    return 0;
}
