#include <stdio.h>

int my_while(int entrada, int entradaDois, int contador){
    if(contador>0){
        if((contador%entrada==0) && (contador%entradaDois==0)){
            return 1+my_while(entrada, entradaDois, contador-1);
        }
        return my_while(entrada, entradaDois, contador-1);
    }
    return 0;
}

int main() {
    int myInput, myInputDois;
    scanf("%d%d", &myInput, &myInputDois);
    printf("%d", my_while(myInput, myInputDois, 49));
	return 0;
}