#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return (fact(n - 1) * n); //-> Recursion
}

int ifact(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i; //-> Iteration
    }
    return fact;
}

int main()
{
    int res;
    res = fact(5);
    cout << res << endl;
    res = 0;
    res = ifact(5);
    cout << res << endl;
    return 0;
}