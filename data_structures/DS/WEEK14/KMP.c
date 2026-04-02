// Pattern Matching using KMP Algorithm
#include <stdio.h>
#include <string.h>

// Function to preprocess the pattern and compute LPS array
void computeLPSArray(char* pattern, int M, int* lps) //Pattern -> a(0) b(1) a(2) b(3) c(4)
{
    int length = 0;  // length of the previous longest prefix suffix
    lps[0] = 0;      // lps[0] is always 0

    int i = 1;
    while (i < M)
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        } else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            } else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Search function
void KMPSearch(char* pattern, char* text)
{
    int M = strlen(pattern);
    int N = strlen(text);

    int lps[M];
    computeLPSArray(pattern, M, lps);

    int i = 0; // index for text[]
    int j = 0; // index for pattern[]
    while (i < N)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];  // Continue searching for next match
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

// Main code
int main()
{
    char text[100], pattern[50];

    printf("Enter the text: ");
    scanf("%[^\n]%*c", text);  // read full line including spaces

    printf("Enter the pattern: ");
    scanf("%[^\n]%*c", pattern);

    KMPSearch(pattern, text);

    return 0;
}

