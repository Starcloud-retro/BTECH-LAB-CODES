//Addition of two polynomials using linked list
#include<stdio.h>
#include<stdlib.h>
struct term
{
    int coeff;
    int exp;
    struct term *next;
};
struct term *createTerm(int coeff, int exp)
{
    struct term *newTerm = (struct term *)malloc(sizeof(struct term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}
void appendterm(struct term **head, int c, int e)
{
    struct term *newTerm = createTerm(c, e);
    if (*head == NULL)
    {
        *head = newTerm;
    }
    else
    {
        struct term *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}
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
        }
        else if (p1->exp < p2->exp)
        {
            appendterm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else
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
}
int main()
{
    struct term *poly1 = NULL;
    struct term *poly2 = NULL;

    // Example polynomial 1: 3x^2 + 4x + 5
    appendterm(&poly1, 4, 3);
    appendterm(&poly1, 3, 2);
    appendterm(&poly1, 2, 1);

    // Example polynomial 2: 2x^2 + 3x + 1
    appendterm(&poly2, 5, 3);
    appendterm(&poly2, 3, 2);
    appendterm(&poly2, 1, 0);

    printf("\nPolynomial 1: ");
    display(poly1);


    printf("\nPolynomial 2: ");
    display(poly2);
    printf("\n");

    struct term *sum = addPolynomials(poly1, poly2);
    
    printf("SUM: ");
    display(sum);
    printf("\n");
    return 0;
}
