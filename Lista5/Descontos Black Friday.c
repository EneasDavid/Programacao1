#include <stdio.h>
int entrada(int loop){
    double precoAntes, precoDepois;
    if(loop<=5){
        scanf("%lf %lf", &precoAntes, &precoDepois);        
        if(precoAntes*.8>=precoDepois){
            return 1+entrada(loop+1);
        }
        return entrada(loop+1);
    }
    return 0;
}
int main(){
    printf("%d",entrada(1));
    return 0;
}