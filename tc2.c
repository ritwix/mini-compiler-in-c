#include <stdio.h>
 void main(){
 	char t,c = 'n';
 	printf("Enter y/n for yes/no \n");
 	scanf("%c",&t);
 	while (1){
 		if(t!='y')
 			break;
 		printf("Enter n to exit, y to continue\n ");
 	}
 }