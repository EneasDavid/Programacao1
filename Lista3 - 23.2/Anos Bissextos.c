#include <stdio.h>

int anosBissextosNoIntervalo(int anoInicio, int anoFim) {
    if (anoInicio>anoFim) return 0;
    if ((anoInicio%4==0 && anoInicio%100!=0) || anoInicio%400==0){
        printf("%d\n", anoInicio);
        return 1+anosBissextosNoIntervalo(anoInicio+1, anoFim);
    } else {
        return anosBissextosNoIntervalo(anoInicio+1, anoFim);
    }
}
int main() {
    int anoInicio, anoFim;
    scanf("%d%d", &anoInicio, &anoFim);
    int totalBissextos=anosBissextosNoIntervalo(anoInicio, anoFim);
    if (totalBissextos<1) {
        printf("-1\n");
    }
    return 0;
}
