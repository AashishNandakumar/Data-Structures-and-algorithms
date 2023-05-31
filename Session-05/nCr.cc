#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return fact(n - 1) * n;
}

int ncr(int n, int r)
{
    int num, den;
    num = fact(n);
    den = fact(r) * fact(n - r);

    return num / den;
}

int nCr(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    else
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main()
{

    cout << ncr(4, 2) << endl;
    cout << nCr(4, 2) << endl;
    return 0;
}