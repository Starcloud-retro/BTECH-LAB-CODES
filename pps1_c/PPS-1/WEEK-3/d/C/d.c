#include<stdio.h>
int main()
{
    int Y; //To CHECK WHETHER a Year is a LEAP YEAR.
    printf("Enter the YEAR(Y):");
    scanf("%d",&Y);
    if ((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0))
    {
        printf("YES, %d is a Leap Year.\n", Y);
    }
    else
    {
        printf("NO, %d is not a Leap Year.\n", Y);
    }

    return 0;
}