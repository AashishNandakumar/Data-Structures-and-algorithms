#include <iostream>
#include <stdio.h>
using namespace std;

void TOH(int n, int a, int b, int c)
{
    if (n > 0)
    {
        TOH(n - 1, a, c, b);
        printf("From %d to %d\n", a, c);
        TOH(n - 1, b, a, c);
    }
}

int main()
{
    TOH(5, 1, 2, 3);
    return 0;
}