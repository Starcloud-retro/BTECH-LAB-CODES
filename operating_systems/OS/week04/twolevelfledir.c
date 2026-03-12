#include<stdio.h>
#include<string.h>

struct directory
{
    char dname[20];
    char files[20][20];
    int count;
};

struct directory dir[10];

void main()
{
    int dcount=0,i,j,ch;
    char d[20],f[20];

    while(1)
    {
        printf("\n1.Create Dir\n2.Create File\n3.Display\n4.Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Directory name: ");
                scanf("%s",dir[dcount].dname);
                dir[dcount].count=0;
                dcount++;
                break;

            case 2:
                printf("Enter directory: ");
                scanf("%s",d);

                for(i=0;i<dcount;i++)
                {
                    if(strcmp(d,dir[i].dname)==0)
                    {
                        printf("File name: ");
                        scanf("%s",dir[i].files[dir[i].count]);
                        dir[i].count++;
                    }
                }
                break;

            case 3:
                for(i=0;i<dcount;i++)
                {
                    printf("\n%s:",dir[i].dname);
                    for(j=0;j<dir[i].count;j++)
                        printf(" %s",dir[i].files[j]);
                }
                break;

            case 4:
                return;
        }
    }
}
