#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define x 'X'
#define o 'O'
#define e ' '
#define t 'T'
char h,c,pw,w;
int p[2]={0,1};
int b[9]={8,1,6,3,5,7,4,9,2};
char board[9];
int moves[9];
int ec=0;
char turn;
void instruction()
{
    printf("\nBoard Position Instructions:\n\n");
    printf("\t 8 | 1 | 6 \n");
    printf("\t-----------\n");
    printf("\t 3 | 5 | 7 \n");
    printf("\t-----------\n");
    printf("\t 4 | 9 | 2 \n");
}
int validateyn()
{
    char response;
    while(1)
    {
        printf("\nDo you choose to play first? Enter (y/n): ");
        scanf("%c",&response);
        response=tolower(response);
        if (response=='y')
        {
            return response;
            break;
        }
        else if (response=='n')
        {
            return response;
            break;
        }
    }
}
int validatenum(int pos)
{
    if(pos<=0 || pos>=10)
    {
        printf("\n%d is not in expected range\n",pos);
        return 0;
    }
    else
    {
        return 1;
    }
}    
void player()
{
    char first;
    first=validateyn();
    if(first=='y')
    {
        h=x;
        turn='h';
        c=0;
    }
    else
    {
        
    }
}