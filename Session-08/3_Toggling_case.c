#include <stdio.h>

int main()
{
    char a[] = "WeLcOmE";
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] >= 65 && a[i] <= 90) // range of upper-case
            a[i] += 32;
        else if (a[i] >= 97 && a[i] <= 122) // range of lower-case
            a[i] -= 32;
    }
    printf("%s", a);
    return 0;
}