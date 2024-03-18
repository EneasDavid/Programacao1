#include <stdio.h>
int main() {
    double qtn;
    char tipo;
    scanf("%lf\n%c", &qtn,&tipo);
    switch(tipo){
        case 'G':
            if(qtn<=20){
               printf("R$ %.2f",(2.5*qtn)*.96); 
            }else{
               printf("R$ %.2f",(2.5*qtn)*.94); 
            }
            break;
        case 'A':
            if(qtn<=20){
               printf("R$ %.2f",(1.9*qtn)*.97);
            }else{
               printf("R$ %.2f",(1.9*qtn)*.95); 
            }
            break;
        case 'D':
            if(qtn>25){
               printf("R$ %.2f",(1.66*qtn)*.96); 
            }else{
               printf("R$ %.2f",1.66*qtn); 
            }
            break;
    }
	return 0;
}