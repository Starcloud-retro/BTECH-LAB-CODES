//ftell() and rewind()
#include<stdio.h>
void main()
{
    int n;
    char ch;
    FILE *fp;
    fp = fopen("sairam.txt","w");
    fputs("Hello, Happy day is Greater, also said to be a day.",fp);

    n = ftell(fp);
    printf("\nCurrent Position is %d",n);

    rewind(fp);

    n = ftell(fp);
    printf("\n\nCurrent Position is %d",n);


    //fseek()
    fseek(fp, 5, SEEK_SET);  // Skip first 5 characters

    ch = fgetc(fp);     // Read the 6th character
    printf("\nCharacter at position 6: %c\n", ch);

    fclose(fp);

}