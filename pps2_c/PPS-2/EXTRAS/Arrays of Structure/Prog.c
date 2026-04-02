#include <stdio.h>
struct STUDENT
{
    int ID;
    char NAME[20];
    int Marks[10];
};
int main()
{
    int n, i, j, sum, sub;
    printf("\nEnter Number of Students: ");
    scanf("%d",&n);
    struct STUDENT s[n];
    printf("\nTOTAL Number of Subjects: ");
    scanf("%d",&sub);
    printf("\nEnter STUDENT DETAILS: \n");
    for(i = 0; i < n; i++)
    {
        printf("\nID: ");
        scanf("%d",&s[i].ID);
        printf("\nNAME: ");
        scanf("%s",s[i].NAME);
        printf("\nMARKS: ");
        for(j = 0; j < sub; j++)
            scanf("%d",&s[i].Marks[j]);
    }
    printf("\nSTUDENT's REPORT: \n");
    for(i = 0; i < n; i++)
    {
        printf("\nID: %d\nNAME: %s\n",s[i].ID,s[i].NAME);
        sum =0;
        for(j = 0; j < sub; j++)
        {
            sum = sum + s[i].Marks[j];
        }
        printf("Total Marks: %d\n",sum);
    }
    return 0;
}