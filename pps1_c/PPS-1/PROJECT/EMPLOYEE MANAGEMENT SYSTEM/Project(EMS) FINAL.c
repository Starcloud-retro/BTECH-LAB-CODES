/*
    PPS-1 PROJECT:
    EMPLOYEE MANAGEMENT SYSTEM: 
    TEAM MEMBERS:
        Y. KARTHIK
        RISHIT GHOSH
        SHAIK ZAHEER ABBAS
*/

#include<stdio.h>
#include<math.h>

float empda(float);     // Employee Dearness Allowance
float empta(float);     // Employee Travel Allowance
float emphpl(float);    // Employee Pay-cut Leaves
float emppf(float);     // Employee Provident Fund
float mory(float);      // Monthly OR Yearly Salary
float empbonus(float);  // Employee Bonus
float emptax(float);    // Employee Tax

int main()
{
    printf("EMPLOYEE MANAGEMENT SYSTEM\n");
    int val,x=1;
    float bsp, a, b, c, d, e, f, g, p, q, s, t,u,v,z;
    char name[50], designation[50];
    while(x==1)
    {
        printf("\nEnter Employee First Name: ");
        scanf("%s",&name);
        printf("\nEnter Employee Designation: ");
        scanf("%s",&designation);
        printf("\nEnter the Basic Pay of the Employee for a month: ");
        scanf("%f", &bsp);

    Requirements:
        printf("Choose a requirement:\n1. Dearness Allowance\n2. Travel Allowance\n3. Pay-cut Leaves\n4. Provident Fund\n5. Bonus\n6. Tax\n7. Total salary\n:");
        scanf("%d", &val);
        switch (val)
        {
            case 1:
                a = empda(bsp); // Function call for Dearness Allowance
                p = mory(a);
                printf("%s\n%s",name,designation);
                printf("\nDearness Allowance: %f\n",p);
                break;
            case 2:
                b = empta(bsp); // Function call for Travel Allowance
                q = mory(b);
                printf("%s\n%s",name,designation);
                printf("\nTravel Allowance: %f\n", q);
                break;
            case 3:
                c = emphpl(bsp); // Function call for Pay-cut Leaves
                printf("%s\n%s",name,designation);
                printf("\nPay-cut Leaves Deduction: %f\n", c);
                break;
            case 4:
                d = emppf(bsp); // Function call for Provident Fund
                s = mory(d);
                printf("%s\n%s",name,designation);
                printf("\nProvident Fund: %f\n", s);
                break;
            case 5:
                f = empbonus(bsp);  // Function call for Bonus
                u = mory(f);
                printf("%s\n%s",name,designation);
                printf("\nBonus: %f\n", u);
                break;
            case 6:
                g = emptax(bsp); // Function call for Tax
                v = mory(g);
                printf("%s\n%s",name,designation);
                printf("\nTax: %f\n", v);
                break;
            case 7:
                e = bsp + empda(bsp) + empta(bsp) + empbonus(bsp) - emppf(bsp) - emptax(bsp); // Total Salary Calculation
                t = mory(e);
                z = t - emphpl(bsp);
                printf("%s\n%s",name,designation);
                printf("\nTotal Salary: %f\n", z);
                break;
            default:
                printf("Choose any one from the below available options only.\n");
                goto Requirements;
                break;
        }
        printf("\n\n\n\nDo you want to calculate salary of another employee?\nIf 'yes' enter (1) else enter (0) to EXIT.\n:");
        scanf("%d",&x);
    }
    return 0;
}

float empda(float bsp)  // Function definition for Dearness Allowance
{
    float da;
    da = 0.35 * bsp;
    return da;
}

float empta(float bsp)   // Function definition for Travel Allowance
{
    float ta;
    ta = 0.15 * bsp;
    return ta;
}

float emphpl(float bsp)  // Function definition for Pay-cut Leaves
{
    float lv, hs, tl;
    int x;
    printf("Total Number of Full-pay leaves are 3 days per month OR 36 days per year.\n");
    tl = bsp + empda(bsp) + empta(bsp) - emppf(bsp);
    printf("For Monthly enter-(0) OR for Yearly enter-(1)\n:");
    scanf("%d", &x);
    printf("Enter number of Leaves: ");
    scanf("%f", &lv);
    if (x == 0)
    {
        if (lv <= 3)
            return 0;
        else
            hs = (lv - 3) * (tl / 30);
    }
    else
    {
        if (lv <= 36)
            return 0;
        else
            hs = (lv - 36) * (tl / 30);
    }
    return hs;
}

float emppf(float bsp)  // Function definition for Provident Fund
{
    float pf;
    pf = 0.15 * bsp;
    return pf;
}

float mory(float n)    // Function definition for Monthly or Yearly Salary
{
    int x;
    printf("For Monthly enter-(0) OR for Yearly enter-(1)\n:");
    scanf("%d", &x);
    if (x == 0)
        return n;
    else
        return 12 * n;
}

float empbonus(float bsp)   // Function definition for Bonus
{
    float bonus;
    bonus = 0.1 * bsp; // 10% of basic salary as bonus
    return bonus;
}

float emptax(float bsp)     // Function definition for Tax
{
    float tax;
    tax = 0.07 * bsp; // 7% of basic salary as tax
    return tax;
}
