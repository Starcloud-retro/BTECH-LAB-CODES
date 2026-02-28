//WEEK-13; 2Q) Function to find the sum of even and odd numbers
#include<stdio.h>
void read(int a[20],int n)
{
	int i;
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void print(int a[20], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
void sumevenodd(int a[20],int n,int *sumptreven,int *sumptrodd)
{
int i;                          
	for(i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			*sumptreven=*sumptreven+a[i];
		}
		else
		{
			*sumptrodd=*sumptrodd+a[i];
		}
	}
}
int main()
{
	int a[20],n,sumeven=0,sumodd=0;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	read(a,n);
	printf("Array Elements are:\n");
	print(a,n);
	sumevenodd(a,n,&sumeven,&sumodd);
	printf("\nSum of EVEN Numbers: %d",sumeven);
	printf("\nSum of ODD Numbers: %d",sumodd);
	return 0;
}