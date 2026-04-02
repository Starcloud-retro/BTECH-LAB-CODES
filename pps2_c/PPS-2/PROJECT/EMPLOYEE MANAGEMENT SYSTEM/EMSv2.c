/*
    PPS-2 PROJECT: V2
    EMPLOYEE MANAGEMENT SYSTEM (Using Linked List): 
    TEAM MEMBERS:
        M. SAI KRISHNA
        RISHIT GHOSH
        SHAIK ZAHEER ABBAS
        Y. KARTHIK
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// Defining the linked list structure
typedef struct Employee
{
    char name[50];          // Employee's name
    char designation[50];   // Employee's designation
    float basicPay;         // Basic pay of the employee
    struct Employee *next;  // Pointer to the next employee node
} Employee;

// Function Prototypes
void requirements(Employee *head);
int genMORY();
void monthORyear(int, float);
int AnotherCatg(Employee *head);
float empda(float);
float empta(float);
float emphpl(float);
float emppf(float);
float empbonus(float);
float emptax(float);
void addEmployee(Employee **head, char name[], char designation[], float bsp);
void displayEmployee(Employee *employee);

int main()
{
    printf("EMPLOYEE MANAGEMENT SYSTEM\n");
    int x = 1, flag;  // Control variable for loop
    float bsp;  // Variable to hold basic pay
    char name[50], designation[50], ch;
    Employee *head = NULL;  // Initialize linked list head as NULL

    while (x == 1)
    {
        flag=1;
        // Input employee details
        printf("\nEnter Employee Name: ");
        scanf(" %[^\n]", name);  // Read full name (including spaces)
        printf("Enter Employee Designation: ");
        scanf("%s", designation);
        printf("Enter the Basic Pay of the Employee for a month: ");
        scanf("%f", &bsp);

        // Add employee to the linked list
        addEmployee(&head, name, designation, bsp);

        // Process requirements for the current employee
        requirements(head);

        // Allow user to check additional categories for the current employee
        while(flag != 0)
        {
            if(!AnotherCatg(head))
            {
                flag = 0; //Exits additional categories selection
            }
        }
        
        // Ask if the user wants to calculate for another employee
        printf("\nDo you want to calculate salary of another employee? If 'yes', enter (1); else enter (0) to EXIT.\n:");
        scanf("%d", &x);
    }

    printf("\nExiting Employee Management System...\n");
    return 0;
}

// Function to handle requirements for an employee
void requirements(Employee *head)
{
    int val;
    float a, b, c, d, e, f, g, z;

    // Ensure we operate on the most recently added employee
    Employee *currentEmployee = head;

    // Display options for the user
    printf("Choose a requirement:\n1. Dearness Allowance\n2. Travel Allowance\n3. Pay-cut Leaves\n4. Provident Fund\n5. Bonus\n6. Tax\n7. Total salary\n8.Exit\n:");
    scanf("%d", &val);

    switch (val)
    {
        case 1: // Dearness Allowance
                a = empda(currentEmployee->basicPay);
                displayEmployee(currentEmployee);
                printf("\nDearness Allowance:");
                monthORyear(genMORY(), a);
                break;

        case 2: // Travel Allowance
                b = empta(currentEmployee->basicPay);
                displayEmployee(currentEmployee);
                printf("\nTravel Allowance:");
                monthORyear(genMORY(), b);
                break;

        case 3: // Pay-cut Leaves
                c = emphpl(currentEmployee->basicPay);
                displayEmployee(currentEmployee);
                printf("\nPay-cut Leaves Deduction: %f\n", c);
                break;

        case 4: // Provident Fund
                d = emppf(currentEmployee->basicPay);
                displayEmployee(currentEmployee);
                printf("\nProvident Fund:");
                monthORyear(genMORY(), d);
                break;

        case 5: // Bonus
                f = empbonus(currentEmployee->basicPay);
                displayEmployee(currentEmployee);
                printf("\nBonus:");
                monthORyear(genMORY(), f);
                break;

        case 6: // Tax
                g = emptax(currentEmployee->basicPay);
                displayEmployee(currentEmployee);
                printf("\nTax:");
                monthORyear(genMORY(), g);
                break;

        case 7: // Total Salary
                e = currentEmployee->basicPay + empda(currentEmployee->basicPay) + empta(currentEmployee->basicPay) + empbonus(currentEmployee->basicPay) - emppf(currentEmployee->basicPay) - emptax(currentEmployee->basicPay);
                z = e - emphpl(currentEmployee->basicPay);  // Deduct leave pay-cuts
                displayEmployee(currentEmployee);
                printf("\nTotal Salary:");
                monthORyear(genMORY(), z);
                break;

        case 8 :exit(0);

        default: // Invalid option
                printf("Invalid option. Please try again.\n");
                requirements(head);  // Retry with valid input
                break;
    }
}

//Allow the user to check additional categories
int AnotherCatg(Employee *head)
{
    char sel;
    printf("\nWant to check another category for the user? [Y/N]\n:");
    scanf(" %c", &sel);

    // Handle valid input
    if (sel == 'Y' || sel == 'y')
    {
        requirements(head); // Allow the user to select another category
        return 1;           // Continue checking for more categories
    } else if (sel == 'N' || sel == 'n')
    {
        printf("\nExiting category selection for this user.\n");
        return 0;           // Stop checking categories
    } else
    {
        // Handle invalid input
        printf("Invalid input! Please enter 'Y' or 'N'.\n");
        return AnotherCatg(head); // Retry for invalid input
    }
}

// Function to determine if monthly or yearly calculation is needed
void monthORyear(int choice, float amount)
{
    char K;
    if (choice == 0)
    {  // Monthly
        printf("Monthly : %f\n", amount);
        printf("Want to Check for Yearly? [Y/N]\n:");
        scanf(" %c",&K);
        if(K == 'Y' || K == 'y')
        {
            printf("Yearly : %f\n", amount * 12);
        }
    }
    else if (choice == 1)
    {  // Yearly
        printf("Yearly : %f\n", amount * 12);
        printf("Want to Check for Monthly? [Y/N]\n:");
        scanf(" %c",&K);
        if(K == 'Y' || K == 'y')
        {
            printf("Monthly : %f\n", amount);
        }
    }
    else
    {
        printf("Invalid choice! Please retry.\n");
    }
}

// Function to fetch user's choice for monthly or yearly
int genMORY()
{
    int choice;
    printf("\nFor Monthly enter-(0) OR for Yearly enter-(1)\n:");
    scanf("%d", &choice);
    return choice;  // Return selection
}

// Function to add an employee node to the linked list
void addEmployee(Employee **head, char name[], char designation[], float bsp)
{
    Employee *newEmployee = (Employee *)malloc(sizeof(Employee));  // Allocate memory
    strcpy(newEmployee->name, name);  // Copy name
    strcpy(newEmployee->designation, designation);  // Copy designation
    newEmployee->basicPay = bsp;  // Set basic pay
    newEmployee->next = *head;  // New node points to current head
    *head = newEmployee;  // Head points to the new node
}

// Function to display employee details
void displayEmployee(Employee *employee)
{
    printf("\nEmployee Name: %s", employee->name);
    printf("\nEmployee Designation: %s", employee->designation);
}

// Functions to calculate various components
float empda(float bsp)
{
    return 0.35 * bsp;
}  // Dearness Allowance

float empta(float bsp)
{
    return 0.15 * bsp;
}  // Travel Allowance

float emphpl(float bsp)
{  // Pay-cut Leaves
    float lv, deduction = 0;
    printf("Enter number of leaves taken: ");
    scanf("%f", &lv);
    deduction = (lv > 3) ? (lv - 3) * (bsp / 30) : 0;  // Deduct for excess leaves
    return deduction;
}

float emppf(float bsp)
{
    return 0.15 * bsp;
}  // Provident Fund

float empbonus(float bsp)
{
    return 0.1 * bsp;
}  // Bonus

float emptax(float bsp)
{
    return 0.07 * bsp;
}  // Tax