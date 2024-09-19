#include<stdio.h>
int main()
{
	int arr[]={10,20,30,40,50};
	int max=arr[0];
	int i;
	int n=sizeof(arr)/sizeof(arr[0]);
	for(i=1;i<n;i++)
	{
		if(max>arr[i])
		{
			max=arr[i];
		}
	}
	printf("Maximum element is %d",max);
}