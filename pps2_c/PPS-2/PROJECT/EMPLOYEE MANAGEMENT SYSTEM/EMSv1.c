/*
    PPS-2 PROJECT: Version 1.0
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
int AnotherCatg(Employee *head);
int genMorY();
void monthORyear(int, float);
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
    int count = 1;  // Control variable for loop
    char name[50], designation[50];
    float basicPay;
    Employee *head = NULL;  // Initialize linked list head as NULL

    while (count == 1)
    {
        // Input employee details
        printf("\nEnter Employee Name: ");
        scanf(" %[^\n]", name);  // Read full name (including spaces)
        printf("Enter Employee Designation: ");
        scanf("%s", designation);
        printf("Enter the Basic Pay of the Employee for a month: ");
        scanf("%f", &basicPay);

        // Add employee to the linked list
        addEmployee(&head, name, designation, basicPay);

        // Process requirements for the current employee
        requirements(head);

        // Allow user to check additional categories for the current employee
        while (AnotherCatg(head));

        // Ask if the user wants to calculate for another employee
        printf("\nDo you want to calculate salary of another employee? If 'yes', enter (1); else enter (0) to EXIT.\n:");
        scanf("%d", &count);
    }
    printf("\nExiting Employee Management System...\n");
    return 0;
}

// Function to handle requirements for an employee
void requirements(Employee *head)
{
    int val;
    float a, b, c, d, e, f, g, z;

    Employee *currentEmployee = head;  // Operate on the most recently added employee

    printf("Choose a requirement:\n1. Dearness Allowance\n2. Travel Allowance\n3. Pay-cut Leaves\n4. Provident Fund\n5. Bonus\n6. Tax\n7. Total salary\n:");
    scanf("%d", &val);

    // Validate input
    if (val < 1 || val > 7)
    {
        printf("Invalid option. Please try again.\n");
        requirements(head);  // Retry
        return;  // Exit current execution
    }

    // Adjusted switch case from CODE2:
    switch (val)
    {
        case 1: // Dearness Allowance
                a = empda(currentEmployee->basicPay);
                displayEmployee(currentEmployee);
                printf("\nDearness Allowance:");
                monthORyear(genMorY(), a);
                break;

        case 2: // Travel Allowance
                b = empta(currentEmployee->basicPay);
                displayEmployee(currentEmployee);
                printf("\nTravel Allowance:");
                monthORyear(genMorY(), b);
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
                monthORyear(genMorY(), d);
                break;

        case 5: // Bonus
                f = empbonus(currentEmployee->basicPay);
                displayEmployee(currentEmployee);
                printf("\nBonus:");
                monthORyear(genMorY(), f);
                break;

        case 6: // Tax
                g = emptax(currentEmployee->basicPay);
                displayEmployee(currentEmployee);
                printf("\nTax:");
                monthORyear(genMorY(), g);
                break;

        case 7: // Total Salary
                e = currentEmployee->basicPay + empda(currentEmployee->basicPay) + empta(currentEmployee->basicPay) + empbonus(currentEmployee->basicPay) - emppf(currentEmployee->basicPay) - emptax(currentEmployee->basicPay);
                z = e - emphpl(currentEmployee->basicPay);
                displayEmployee(currentEmployee);
                printf("\nTotal Salary:");
                monthORyear(genMorY(), z);
                break;

        default:
                printf("Invalid option. Please try again.\n");
                requirements(head);  // Retry with valid input
                break;
    }
}

// Updated function to allow the user to check additional categories
int AnotherCatg(Employee *head)
{
    char sel;
    printf("\nWant to check another category for the user? [Y/N]\n:");
    scanf(" %c", &sel);

    // For valid input
    if (sel == 'Y' || sel == 'y')
    {
        requirements(head); // Allow the user to select another category
        return 1;           // Continue checking for more categories
    }
    else if (sel == 'N' || sel == 'n')
    {
        printf("\nExiting category selection for this user.\n");
        return 0;           // Stop checking categories
    }
    else
    {
        // Handle invalid input
        printf("Invalid input! Please enter 'Y' or 'N'.\n");
        return AnotherCatg(head); // Retry for invalid input
    }
}

// Function to determine if monthly or yearly calculation is needed
void monthORyear(int choice, float amount)
{
    printf("\nCalculations:\n");
    if (choice == 0)
    {
        printf("Monthly : %f\n", amount);
        printf("Yearly : %f\n", amount * 12);
    }
    else if (choice == 1)
    {  
        printf("Yearly : %f\n", amount * 12);
        printf("Monthly : %f\n", amount);
    }
    else
    {
        printf("Invalid choice! Please retry.\n");
    }
}

// Function to fetch user's choice for monthly or yearly
int genMorY()
{
    int choice;
    printf("\nFor Monthly enter-(0) OR for Yearly enter-(1)\n:");
    scanf("%d", &choice);
    return choice;
}

// Function to add an employee node to the linked list
void addEmployee(Employee **head, char name[], char designation[], float bsp)
{
    Employee *newEmployee = (Employee *)malloc(sizeof(Employee));  
    strcpy(newEmployee->name, name);  
    strcpy(newEmployee->designation, designation);  
    newEmployee->basicPay = bsp;  
    newEmployee->next = *head;  
    *head = newEmployee;  
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
}

float empta(float bsp)
{
    return 0.15 * bsp;
}  

float emphpl(float bsp)
{  
    float lv, deduction = 0;
    printf("Enter number of leaves taken: ");
    scanf("%f", &lv);
    deduction = (lv > 3) ? (lv - 3) * (bsp / 30) : 0;  
    return deduction;
}

float emppf(float bsp)
{
    return 0.15 * bsp;
}

float empbonus(float bsp)
{
    return 0.1 * bsp;
}  

float emptax(float bsp)
{
    return 0.07 * bsp;
}