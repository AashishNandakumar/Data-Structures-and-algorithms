#include <iostream>
using namespace std;

int fib(int n)
{
    if (n <= 1)
        return n;
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}
int fib1(int n)
{
    int t0 = 0, t1 = 1, s = 0, i;
    if (n <= 1)
        return n;
    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}
int F[100];
int fib2(int n) // memoization
{
    if (n <= 1)
    {
        F[n] = n;
        return F[n];
    }
    else
    {
        if (F[n - 2] == -1)
            F[n - 2] = fib2(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] == fib2(n - 1);
        F[n] = F[n - 2] + F[n - 1];
        return F[n];
    }
}

int main()
{
    for (int i = 0; i < 100; i++)
        F[i] = -1;
    cout << fib(5) << endl;
    cout << fib1(5) << endl;

    cout << fib2(5) << endl;
    return 0;
}