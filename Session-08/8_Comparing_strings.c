#include <stdio.h>

void Compare(char *A, char *B)
{
    int i, j;
    for (i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++)
    {
        if (A[i] != B[j])
            break;
    }
    if (A[i] == B[j])
        printf("Both Strings are equal");
    else if (A[i] > B[j])
        printf("String A is bigger");
    else
        printf("String B is bigger");
}
int main()
{
    char *A = "painter";
    char *B = "painting";
    Compare(A, B);

    return 0;
}