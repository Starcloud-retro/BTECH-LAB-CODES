//Write a C-Program to delete characters from a given string and position.
#include <stdio.h>
#include <string.h>
int main()
{
    char s1[15];
    int pos, i, j, len, n;
    printf("Enter a string: ");
    gets(s1); // Note: gets() is unsafe, consider using fgets() in real applications
    printf("Enter the position to start deleting characters: ");
    scanf("%d", &pos);
    printf("Enter the number of Characters to Delete: ");
    scanf("%d",&n);
    len=strlen(s1);
    if(pos>len)
    {
        printf("Deletion Not Possible.");
    }
    else
    {
        for(i=pos,j=pos+n;j<len;i++,j++)
        {
            s1[i]=s1[j];
        }
    }
    s1[i]='\0';
    puts(s1);
    return 0;
}