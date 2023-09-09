#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if(y<x){
        x=y;
    }
    if(z<y){
        x=z;
    }
    printf("%d\n", x);
	return 0;
}