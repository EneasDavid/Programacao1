#include <stdio.h>
int main ( )
{
    int n, conta =7;
    scanf("%d", &n);
    if(n<=10){
    }else if (n<=30) {
        conta +=(n-10)*1;
    }else if (n<=100) {
        conta +=20 + (n-30)*2;
    }else if (n > 100) {
        conta +=20 + 140 + (n-100)*5;
    }
    printf("%d",conta);
    return 0 ;
}