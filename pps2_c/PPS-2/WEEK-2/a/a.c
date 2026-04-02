//Write a C-Program to convert Roman Number to Decimal Number
#include<stdio.h>
#include<string.h>
int main()
{
    char roman[10];
    int deci = 0, length, i, d[10];
    printf("\nRoman Equivalent to Decimal:\n");
    printf("\nEnter a Valid Roman Number: ");
    scanf("%s",roman);
    length = strlen(roman);
    for(i=0;i<length;i++)
    {
        switch(roman[i])
        {
            case 'm' :
            case 'M' : d[i] = 1000; break;
            case 'd' :
            case 'D' : d[i] = 500; break;
            case 'c' :
            case 'C' : d[i] = 100; break;
            case 'l' :
            case 'L' : d[i] = 50; break;
            case 'x' :
            case 'X' : d[i] = 10; break;
            case 'v' :
            case 'V' : d[i] = 5; break;
            case 'i' :
            case 'I' : d[i] = 1; break;
            default  : printf("Enter a Valid Roman Number !!");
        }
    }
    for(i = 0; i < length; i++)
    {
        if(i==length-1 || d[i] >= d[i+1])
            deci += d[i];
        else
            deci -= d[i];
    }
    printf("\n%d", deci);
    return 0;
}
