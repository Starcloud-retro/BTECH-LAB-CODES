//use of fpritnf, fscanf
#include<stdio.h>
void main()
{
    FILE *f;
    char name1[15],name2[15];
    int age1, age2;
    float grade1, grade2;
    f = fopen("ram.txt","w");
    //fprintf()
    printf("\nEnter Name, Age, Grade:\n");
    scanf("%s %d %f", name1, &age1, &grade1);
    fprintf(f,"%s %d %f\n",name1, age1, grade1);
    fclose(f);


    //fscanf()
    f = fopen("ram.txt","r");
    fscanf(f,"%s %d %f",name2, &age2, &grade2);
    printf("\nName: %s\nAge: %d\nGrade: %f",name2, age2, grade2);
    fclose(f);
}
