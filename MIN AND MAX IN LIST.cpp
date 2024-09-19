#include<stdio.h>
int main()
{
  int n;
	printf("Enter the size of the array");
	scanf("%d",&n);
		int arr[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int min=arr[0],max=arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i]<min)
		{
			min=arr[i];
		}
}
		for(i=1;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	printf("the minimum element is  %d ",min);
	printf("the maximum element is  %d ",max);
	return 0;
}