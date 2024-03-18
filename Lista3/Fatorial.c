#include <stdio.h>
int fat(int x){
    return x>1?x*fat(x-1):1;
}
int main() {
    int entrada;
    scanf("%d", &entrada);
    if(entrada<0){
        return 0;
    }else{
        printf("%d\n", fat(entrada));
        return main();
    }
}