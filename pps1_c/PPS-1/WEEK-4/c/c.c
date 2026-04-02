#include<stdio.h>
int main()
{
    int n;
    printf("Enter the Number(n):");
    scanf("%d",&n);
    {
        if (n%2==0)
        {
            if (n%4==0)
            {
                if (n%8==0)
                printf("It is a MULTIPLE of 2, 4, 8.");
                else
                printf("It is a MULTIPLE of 2,4. But not a MULTIPLE of 8.");
            }
            else
            printf("It is a MULTIPLE of 2. But not a MULTIPLE of 4, 8.");
        }
        else
        printf("It is not a MULTIPLE of 2, 4, 8.");
    }
    return 0;
}