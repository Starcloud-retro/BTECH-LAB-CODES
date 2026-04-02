#include<stdio.h>
int main()
{
    int m;
    printf("Enter the Marks Scored(m):");
    scanf("%d",&m);
    if (m<=30)
        {
            printf("FAILED. SCORE:%d",m);
        }
    else
        {
            if (31<=m && m<=50)
            {
                printf("PASSED with C-Grade. SCORE:%d",m);
            }
            else if (51<=m && m<=60)
            {
                printf("PASSED with B-Grade. SCORE:%d",m);
            }
            else if (61<=m && m<=75)
            {
                printf("PASSED with A-Grade. SCORE:%d",m);
            }
            else if (m>75)
            {
                printf("PASSED with Distinction. SCORE:%d",m);
            }
            else
            {
                printf("ERROR. Please Re-Enter the Marks.");
            }
            return 0;        
            
        }
}