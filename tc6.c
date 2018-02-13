//else doesn't follow an if block
#include <stdio.h>
int main(){
	int num=5;
	if(!num==0)
		printf("OK\n");
	printf("NOK\n");
	else
		printf("DOK\n");
	printf("%d",num);
	return 1;
}