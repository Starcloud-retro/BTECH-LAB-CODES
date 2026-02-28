//Write a C-Program to store the information (name, roll no., and branch) of a student using UNIONS
#include<stdio.h>
union student
{
	int rno;
	char name[25];
	char branch[5];
};
int main()
{
	union student u1;
	printf("Enter R.No: ");
	scanf("%d",&u1.rno);
	printf("Roll No.: %d", u1.rno);
	printf("\n\nEnter Name: ");
	scanf("%s",u1.name);
	printf("Name: %s",u1.name);
	printf("\n\nEnter Branch: ");
	scanf("%s",u1.branch);
	printf("Branch: %s",u1.branch);
	return 0;
}
