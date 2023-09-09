#include <stdio.h>
int ePrimo(int digito, int valorVariante){
    if(digito<2 || digito%2==0 && digito!=2){
        return 0;
    }
    return digito%valorVariante?1:ePrimo(digito,valorVariante+1);
}
void entrada(){
    int input;
    scanf("%d", &input);
    if(input!=-1){
        printf("%d\n",ePrimo(input,2));
        entrada();
    }
}
int main() {
    entrada();
	return 0;
}