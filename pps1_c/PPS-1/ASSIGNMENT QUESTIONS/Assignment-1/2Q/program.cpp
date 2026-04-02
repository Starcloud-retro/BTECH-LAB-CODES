#include<Stdio.h>
int main()
{
    int n, i, r, x=0;
    printf("Enter the Number(N):");
    scanf("%d",&n);
    r=n;
    i=1;
    while (n>=i)
    {
        x=x+i;
        i++;
    }
    printf("\nSUM of (%d) Numbers is:%d",r,x);
    
}