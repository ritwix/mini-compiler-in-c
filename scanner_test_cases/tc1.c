#include <stdio.h>
//function prototype
int square (int x);
/*hello
	hi
	goodbye*/
void main(){
	int n,l;
	scanf ("%d", &n );
	//function call
	l=square(n);
	
}

int square (int x){			//function definition
	int l; 
	l= x * x;
	return l;
}
