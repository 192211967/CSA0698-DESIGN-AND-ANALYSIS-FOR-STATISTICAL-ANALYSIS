#include<stdio.h>
void swap(int*a,int*b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void sort(int arr[],int n)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			
			if(arr[j]<arr[min])
			{
			min=j;	
			}
		}
		swap(&arr[min],&arr[i]);
	}
	for(i=0;i<n;i++)
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