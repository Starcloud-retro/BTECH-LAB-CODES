//Write a C-Program to implement inter-function communication by passing pointers to a structure:
#include<stdio.h>
#include<stdlib.h>
struct point
{
    int x;
    int y;
};
void display(struct point *ptr);
void main()
{
    struct point s1={3,5};
    display(&s1);
}
void display(struct point *ptr)
{
    printf("The Coordinates of the Points are: %d, %d",ptr->x, ptr->y);
}