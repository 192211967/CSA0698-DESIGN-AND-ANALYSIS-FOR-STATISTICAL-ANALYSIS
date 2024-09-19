#include<stdio.h>
int main()
{
	int n,c=0,i;
	printf("Enter a number: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			c=c+1;
		}
	}
	if(c==2)
	{
		printf("Given number is prime");
	}
	else
	{
		printf("Not a prime number");
	}
}