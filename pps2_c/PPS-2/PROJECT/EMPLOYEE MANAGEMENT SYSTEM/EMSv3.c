//MADE with AI
/*
FEATURES INCLUDED:
    Persistence – Employees are saved and retrieved even after the program exits.
    Sorting Feature – Employees are listed in order of salary for better visualization.
    Structured Menu – No more repetitive prompts—users navigate interactively.
    Memory Management – Prevents leaks with proper free() calls.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the linked list structure
typedef struct Employee
{
    char name[50];         
    char designation[50];  
    float basicPay;        
    struct Employee *next;
} Employee;

// Function Prototypes
void addEmployee(Employee **head, char name[], char designation[], float bsp);
void displayEmployees(Employee *head);
void saveToFile(Employee *head);
void loadFromFile(Employee **head);
void freeMemory(Employee **head);
void sortEmployees(Employee **head);
void menu(Employee **head);

int main()
{
    Employee *head = NULL;
    loadFromFile(&head);  // Load existing employees from file
    menu(&head);
    saveToFile(head);     // Save employees before exiting
    freeMemory(&head);    // Free allocated memory
    return 0;
}

// Function to display menu and handle choices
void menu(Employee **head)
{
    int choice;
    while (1)
    {
        printf("\nEMPLOYEE MANAGEMENT SYSTEM\n");
        printf("1. Add Employee\n2. Display Employees\n3. Sort Employees\n4. Exit\nChoose: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            char name[50], designation[50];
            float bsp;
            printf("\nEnter Employee Name: ");
            scanf(" %[^\n]", name);
            printf("Enter Designation: ");
            scanf("%s", designation);
            printf("Enter Basic Pay: ");
            scanf("%f", &bsp);
            addEmployee(head, name, designation, bsp);
        }
        else if (choice == 2)
        {
            displayEmployees(*head);
        }
        else if (choice == 3)
        {
            sortEmployees(head);
            printf("\nEmployees sorted successfully!\n");
        }
        else if (choice == 4)
        {
            printf("\nExiting Employee Management System...\n");
            break;
        }
        else
        {
            printf("\nInvalid choice! Please try again.\n");
        }
    }
}

// Function to add an employee to the linked list
void addEmployee(Employee **head, char name[], char designation[], float bsp)
{
    Employee *newEmployee = (Employee *)malloc(sizeof(Employee));
    strcpy(newEmployee->name, name);
    strcpy(newEmployee->designation, designation);
    newEmployee->basicPay = bsp;
    newEmployee->next = *head;
    *head = newEmployee;
}

// Function to display employees
void displayEmployees(Employee *head)
{
    Employee *current = head;
    printf("\nEmployee List:\n");
    while (current) {
        printf("Name: %s, Designation: %s, Basic Pay: %.2f\n", current->name, current->designation, current->basicPay);
        current = current->next;
    }
}

// Function to save employees to a file
void saveToFile(Employee *head)
{
    FILE *file = fopen("employees.txt", "w");
    Employee *current = head;
    while (current)
    {
        fprintf(file, "%s %s %.2f\n", current->name, current->designation, current->basicPay);
        current = current->next;
    }
    fclose(file);
}

// Function to load employees from a file
void loadFromFile(Employee **head)
{
    FILE *file = fopen("employees.txt", "r");
    if (!file) return;
    char name[50], designation[50];
    float bsp;
    while (fscanf(file, "%s %s %f", name, designation, &bsp) != EOF)
    {
        addEmployee(head, name, designation, bsp);
    }
    fclose(file);
}

// Function to free allocated memory
void freeMemory(Employee **head)
{
    Employee *current = *head;
    while (current)
    {
        Employee *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

// Function to sort employees by salary
void sortEmployees(Employee **head)
{
    if (!*head) return;
    Employee *current, *index;
    float tempPay;
    char tempName[50], tempDesignation[50];

    for (current = *head; current != NULL; current = current->next)
    {
        for (index = current->next; index != NULL; index = index->next)
        {
            if (current->basicPay > index->basicPay)
            {
                // Swap basic pay
                tempPay = current->basicPay;
                current->basicPay = index->basicPay;
                index->basicPay = tempPay;

                // Swap name
                strcpy(tempName, current->name);
                strcpy(current->name, index->name);
                strcpy(index->name, tempName);

                // Swap designation
                strcpy(tempDesignation, current->designation);
                strcpy(current->designation, index->designation);
                strcpy(index->designation, tempDesignation);
            }
        }
    }
}