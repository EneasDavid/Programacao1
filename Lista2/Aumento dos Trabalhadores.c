#include <stdio.h>
int main() {
    double salario, porcentagem;
    scanf("%lf",&salario);
    if(salario>500){
        porcentagem=1.1;
    }else if(salario>300){
        porcentagem=1.07;
    }else{
        porcentagem=1.05;
    }
    printf("%.2f",(double)salario*porcentagem);
	return 0;
}