#include<stdio.h>
void swap(int*a,int*b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void sort(int arr[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j+1],&arr[j]);
			}
		}
	}
	for(i=1;i<n;i++)
	{
		printf("%d",arr[i]);
		printf("\n");
	}
}
int main()
{
	int arr[]={10,20,12,15,30,45,35,88,82};
	int n=sizeof(arr)/sizeof(arr[0]);
	sort(arr,n);
	return 0;
}