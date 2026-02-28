#include<stdio.h>
int main()
{
    int y;
    printf("Enter the Year(Y):");
    scanf("%d",&y);
    if((y%4==0&&y%100!=0)||(y%400==0))
        {
            printf("YES, %d is a LEAP YEAR.",y);
        }
    else
        {
            printf("NO, %d is not a LEAP YEAR.",y);
        }
    return 0;
}