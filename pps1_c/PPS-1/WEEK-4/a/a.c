#include<stdio.h>
int main()
{
    int m;
    printf("Enter the Marks(m):");
    scanf("%d",&m);
    {
        if (m<=30)  //FAILED
        {
            printf("FAILED. SCORED:%d",m);
        }
        else
        {           //Only PASSED
            if (m>=75)
                printf("PASSED with DISTINCTION. SCORED:%d",m);
            else if ((m>=61)&&(m<75))
                printf("PASSED with A-Grade. SCORED:%d",m);
            else if ((m>=51)&&(m<=60))
                printf("PASSED with B-Grade. SCORED:%d",m);
            else if ((m>=31)&&(m<=50))
                printf("PASSED with C-Grade. SCORED:%d",m);
            else
            {       //ERROR
        
                printf("ERROR. Please Re-Enter the MARKS.");
        
            }
        }
    }
}