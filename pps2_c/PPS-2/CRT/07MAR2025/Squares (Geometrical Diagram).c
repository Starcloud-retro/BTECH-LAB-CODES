#include<stdio.h>
int main()
{
    int m, n, k, val;
    int c1, c2;
    printf("\nEnter 'm' , 'n' Values: ");
    scanf("%d%d",&m,&n);
    SELECTION:
    printf("\nSelect any one option of the Following:\n1. Find the total number of Possible Squares from the Geometric Figure\n2. Find the number of Squares of (k*k) from the Geometric Figure\n\t: ");
    scanf("%d",&val);
    switch(val)
    {
        case 1 :
            {
                if(m > n)
                {
                    c1 = ((n * (n + 1) * ((2 * n) + 1)) / 6) + (((m - n) * n * (n + 1)) / 2);
                }
                else
                {
                    c1 = ((m * (m + 1) * ((2 * m) + 1)) / 6) + (((n - m) * m * (m + 1)) / 2);
                }
                printf("\nTOTAL Number of Squares from the Geometrical Figure is: %d", c1);
                break;
            }
        case 2 :
            {
                printf("\nEnter 'k' Value: ");
                scanf("%d", &k);
                int min = (m < n) ? m : n; // Finding the minimum of m and n
                if (k <= min)
                {
                    c2 = (m - k + 1) * (n - k + 1); // Corrected calculation for k*k squares
                    printf("\nThe number of Squares of (%d*%d) from the Geometric Figure is: %d", k, k, c2);
                }
                else
                {
                    printf("\nValue of k is too large for the given dimensions.");
                }
                break;
            }
        default:
            {
                printf("\nChoose any one of the TWO options only.");
                goto SELECTION;
                break;
            }
    }
    return 0;
}