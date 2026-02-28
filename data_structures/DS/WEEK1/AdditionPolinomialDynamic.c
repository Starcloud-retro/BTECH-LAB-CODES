//Addition of Two Polynomials using Linked List
#include <stdio.h>
#include <stdlib.h>

struct term
{
    int coeff;
    int exp;
    struct term *next;
};

// Append a term to the polynomial
void appendterm(struct term **head, int coeff, int exp)
{
    struct term *newTerm = (struct term *)malloc(sizeof(struct term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;

    if (*head == NULL)
    {
        *head = newTerm;
    } else
    {
        struct term *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}

// Add two polynomials
struct term *addPolynomials(struct term *p1, struct term *p2)
{
    struct term *result = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp == p2->exp)
        {
            appendterm(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp)
        {
            appendterm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else
        {
            appendterm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        appendterm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        appendterm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Display the polynomial
void display(struct term *head)
{
    struct term *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
        {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct term *poly1 = NULL;
    struct term *poly2 = NULL;
    int degree, coeff;

    printf("Enter the Degree of Polynomial 1: ");
    scanf("%d", &degree);
    for (int i = degree; i >= 0; i--)
    {
        printf("Enter the Coefficient of x^%d: ", i);
        scanf("%d", &coeff);
        appendterm(&poly1, coeff, i);
    }

    printf("Enter the Degree of Polynomial 2: ");
    scanf("%d", &degree);
    for (int i = degree; i >= 0; i--)
    {
        printf("Enter the Coefficient of x^%d: ", i);
        scanf("%d", &coeff);
        appendterm(&poly2, coeff, i);
    }

    printf("\nPolynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    struct term *sum = addPolynomials(poly1, poly2);
    printf("SUM: ");
    display(sum);

    return 0;
}
