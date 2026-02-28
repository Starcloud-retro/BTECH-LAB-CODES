//Arrays of Structures 
#include<stdio.h>
struct student
{
	int ID;
	char name[20];
	int marks[5];
};
int main()
{
	int i, j, n;
	int sum=0;
	printf("Enter number of Students: ");
	scanf("%d",&n);
	struct student s[n];
	for(i=0;i<n;i++)
	{
		printf("Enter ID: ");
		scanf("%d",&s[i].ID);
		printf("Enter Name: ");
		scanf("%s",s[i].name);
		printf("Enter Marks: ");
		for( j = 0; j < 5; j++)
		{
			scanf("%d",&s[i].marks[j]);
		}
	}
	printf("\nStudent Details are: ");
	for(i=0;i<n;i++)
	{
		printf("\nID: %d\nName: %s\n",s[i].ID,s[i].name);
		sum=0;
		for(j = 0; j < 5; j++)
		{
			sum=sum+s[i].marks[j];
		}
		printf("Total Marks are: %d",sum);
	}
	return 0;
}
