//WEEK-14; 1Q) Function to find the largest number in the array
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, n;
    int *element;
    printf("Input total number of elements (1-100):");
    scanf("%d",&n);
    element=(int*)malloc(sizeof(int));//Memory is allocated for n elements
    if(element==NULL)
    {
        printf("No Memory is Allocated");
        exit(0);
    }
    printf("\n");
    for(i=0;i<n;++i)
    {
        printf("Number %d :",i+1);
        scanf("%d",element+i);
    }
    for(i=0;i<n;++i)
    {
        if(*element<*(element+i))
        {
            *element=*(element+i);
        }
    }
    printf("The Largest Element is:%d",*element);
    return 0;
}