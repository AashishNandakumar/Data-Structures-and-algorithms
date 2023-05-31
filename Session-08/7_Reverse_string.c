#include <stdio.h>

void method1(char *A) // one more array->space complexity
{
    char B[7];
    int i, j;
    for (i = 0; A[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }
    B[j] = '\0';
    printf("Reversed String: %s", B);
}

void Method2(char A[]) // within the same array
{
    char B[7];
    char temp;
    int i, j;
    for (j = 0; A[j] != '\0'; j++)
    {
    }
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    printf("Reversed string is: %s", A);
}
int main()
{
    char A[] = "Aashish";
    // method1(A);
    Method2(A);
}