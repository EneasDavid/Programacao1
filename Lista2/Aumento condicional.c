#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    double s, vAumento, sAfter;
    int pCem;
    scanf("%lf", &s);
    if(s<=280){
        pCem=20;
        vAumento=s*.2;
        sAfter=s*1.2;
    }else if(s<700){
        pCem=15;
        vAumento=s*.15;
        sAfter=s*1.15;
    }else if(s<1500){
        pCem=10;
        vAumento=s*.1;
        sAfter=s*1.1;
    }else{
        pCem=05;
        vAumento=s*.05;
        sAfter=s*1.05;
    }
    printf("%.2f\n%d\n%.2f\n%.2f", s,pCem, vAumento, sAfter);
	return 0;
}