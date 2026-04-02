//use of getw, putw
#include<stdio.h>
void main()
{
    //putw
    int num = 123;
    FILE *f;
    f = fopen("ram.txt", "wb"); //wb -for binary files
    putw(num, f);
    fclose(f);

    //getw
    f = fopen("ram.txt", "rb"); //rb -for binary files
    int read_num = getw(f);
    printf("Read number: %d", read_num);
    fclose(f);
}
