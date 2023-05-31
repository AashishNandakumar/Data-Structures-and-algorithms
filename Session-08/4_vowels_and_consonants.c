#include <stdio.h>

int main()
{
    char A[] = "How are You";
    int vowels = 0, consonants = 0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
            vowels++;
        else if ((A[i] >= 65 && A[i] <= 90) || (A[i] >= 97 && A[i] <= 122))
            consonants++;
    }
    printf("Vowels: %d  Consonants: %d", vowels, consonants);
    return 0;
}                   