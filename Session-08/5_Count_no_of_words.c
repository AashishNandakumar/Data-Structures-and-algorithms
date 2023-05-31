#include <stdio.h>

int main()
{
    char A[] = "Hey man how are    you";
    int word = 1;
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == ' ' && A[i - 1] != ' ') // includes - whatIf multiple blankspaces are included
            word++;
    }
    printf("No of words: %d", word);
    return 0;
}