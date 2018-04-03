#include<stdio.h>
char names[1000][1000];
char temp[1000];

int func(int a,int b)
{
	a = b+1;
	return a+b;
}

void main()
{
/*This
is a
multline comment*/
	char s="awdhwj";
	int n=10,i=2,c=3;
	char x;
	names[i][n] = x;
	func(n,i);
	n = n + i;
	if(i < c)
	{
		n++;
	}
	else
	{
		n--;
	}
	scanf("%d", &n);
	int f;
	func(f,i);
	i = 1;
	do
	{
		scanf("%s", names[i]);
		i++;
	}while(i <= n);
	int j;
	do
	{
		j = i + 1;
	}while(j <= n);

	i = 1;
	do
	{
		printf("%s ", names[i]);
		i++;
	}while(i <= n);
	return;
}
