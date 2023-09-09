#include <stdio.h>
int fatorial(int x){
    /*if(x>1){
        return x*fatorial(x-1);
    }else{
        return 1;
    }*/
    return x>1?x*fatorial(x-1):1;
}
int main() {
    /*int x;
    scanf("%d",&x);
    printf("%d",fatorial(x));*/
    printf("%d",fatorial(getchar()-'0'));
	return 0;
}