//example of pointer referencing and dereferencing in C
#include <stdio.h>

int main()
{
    int a = 42;

    // Single pointer
    int *ptr = &a;

    // Double pointer
    int **dptr = &ptr;

    printf("Value of a: %d\n", a);
    printf("Value using *ptr: %d\n", *ptr);
    printf("Value using **dptr: %d\n", **dptr);

    printf("Address of a: %p\n", &a);
    printf("Address stored in ptr: %p\n", ptr);
    printf("Address stored in dptr: %p\n", dptr);
    printf("Address of ptr: %p\n", &ptr);

    return 0;
}
