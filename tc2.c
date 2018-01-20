#include <stdio.h>
 void main(){
 	char t,c = 'n';
 	printf("%c",c);
 	scanf("%c",&t);
 	while (1){
 		if(t!='y')
 			break;
 		printf("%c\t%c\n",c,t);
 	}
 }