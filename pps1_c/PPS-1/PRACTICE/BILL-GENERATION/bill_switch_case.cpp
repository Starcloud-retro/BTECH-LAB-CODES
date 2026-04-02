#include<stdio.h>
int main()
{
    int val, Q;
    float Amount;
    printf("Choose any one of the Following:\n1. PIZZA\n2. BURGER\n3. SANDWITCH\nEnter the Serial no.:");
    scanf("%d",&val);
    switch (val)
        {
            case 1: printf("\n1. PIZZA - Rs.120");
                    printf("\nEnter Quantity:");
                    scanf("%d",&Q);
                    Amount = Q*120;
                    printf("\nYour Bill is %f",Amount);
                break;
            case 2: printf("\n2. BURGER - Rs.130");
                    printf("\nEnter Quantity:");
                    scanf("%d",&Q);
                    Amount = Q*130;
                    printf("Your BILL is %f",Amount);
                break;
            case 3: printf("\n3. SANDWITCH - Rs.140");
                    printf("\nEnter Quantity:");
                    scanf("%d",&Q);
                    Amount = Q*140;
                    printf("Your BILL is %f",Amount);
                break;
            default:printf("Choose any one from the three!");
                break;
        }    
    return 0;
}