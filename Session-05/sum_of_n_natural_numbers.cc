#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 0)
        return 0;
    else
        return (sum(n - 1) + n); // Is recursion
}

int isum(int n)
{
    int sum = 0, i;
    for (i = 1; i <= n; i++)
    {
        sum = sum + i; // is Iteration
    }
    return sum;
}

int main()
{
    int results;

    results = sum(5);
    cout << results << endl;
    results = 0;
    results = isum(5);
    cout << results << endl;
    return 0;
}
