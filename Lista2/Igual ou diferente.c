#include <stdio.h>
int main() {
    int um, dois, tres;
    scanf("%i %i %i", &um, &dois, &tres);
    if(um==dois && dois==tres){
        printf("1");
    }else if(um!=dois && dois!=tres){
        printf("2");
    }else{
        printf("3");
    }
	return 0;
}