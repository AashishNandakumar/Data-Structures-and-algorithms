#include <iostream>
using namespace std;
int pow(int m, int n)
{
    if (n == 0)
        return 1;
    else
        return (pow(m, n - 1) * m);
}

int newpow(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return (pow(m * m, n / 2));
    else
        return m * (pow(m * m, (n - 1) / 2));
}
int main()
{
    int res;
    res = pow(2, 2);
    cout << res << endl;
    // res = 0;
    // res = newpow(2, 9);
    // cout << res << endl;
    return 0;
}