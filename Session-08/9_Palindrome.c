#include <stdio.h>
#include<stdlib.h>

void Palindrome_or_not(char A[])
{
    int o;
    char *ch;
    int i, j, flag = 0;

    for (o = 0; A[o] != '\0'; o++)
    {
    }
    ch = (char *)malloc(sizeof(char)*o);
    
    
    for ( i = 0; A[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (j = 0; i > 0; i--, j++)
    {
        ch[j] = A[i];
    }
    ch[j] = '\0';
    for (int k = 0; ch[k] != '\0'; k++)
    {
        if (ch[k] == A[k])
            flag = 0;
        else
            flag++;
    }
    if(flag == 0)
        printf("Palindrome");
    else
        printf("Not palindrome");
}

int main()
{
    char A[] = "madam";

    Palindrome_or_not(A);
    return 0;
}