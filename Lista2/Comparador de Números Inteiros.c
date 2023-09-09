#include <stdio.h> 

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
 	printf("%d\n%d\n%d\n%d\n%d\n%d\n",(x>y?1:0),(x==y?1:0),(x<y?1:0),(x!=y?1:0),(x>=y?1:0),(x<=y?1:0));
	return 0;
}