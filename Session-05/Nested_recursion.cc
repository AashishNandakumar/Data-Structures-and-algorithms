#include <iostream>
using namespace std;

int funA(int n)
{
    if (n > 100)
    {
        return (n - 10);
    }
    else
        return funA(funA(n + 11));
}

int main()
{
    int res;
    res = funA(31); 
    cout << res;
    return 0;
}