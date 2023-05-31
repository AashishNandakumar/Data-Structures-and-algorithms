#include <stdio.h>

int main()
{
    char a[] = "HELLO";
    char b[] = "hello";
    for (int i = 0; a[i] != '\0'; i++)
    {
        a[i] = a[i] + 32;
    }
    printf("%s\n", a);

    for (int i = 0; b[i] != '\0'; i++)
    {
        b[i] = b[i] - 32;
    }
    printf("%s", b);
}