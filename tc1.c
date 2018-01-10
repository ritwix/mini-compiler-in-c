#include <stdio.h>
//function prototype
int square (int x);

void main(){
	//int variables
	int n,l;
	printf ("Enter number for finding its square\n");
	scanf ("%d", &n );
	//function call
	l=square(n);
	printf("Square of the entered number is %d", &l);
}

int square (int x){			//function definition
	int l; 
	l= x * x;
	return l;
}
