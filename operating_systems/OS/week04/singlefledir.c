#include<stdio.h>
#include<string.h>

void main()
{
    char dirname[20];
    char files[20][20];
    int n=0,i,choice;

    printf("Enter directory name: ");
    scanf("%s",dirname);

    do
    {
        printf("Enter file name: ");
        scanf("%s",files[n]);

        for(i=0;i<n;i++)
        {
            if(strcmp(files[i],files[n])==0)
            {
                printf("File already exists\n");
                break;
            }
        }

        if(i==n)
            n++;

        printf("Add another file? (1-yes 0-no): ");
        scanf("%d",&choice);

    }while(choice==1);

    printf("\nDirectory: %s\n",dirname);
    printf("Files:\n");

    for(i=0;i<n;i++)
        printf("%s\n",files[i]);
}
