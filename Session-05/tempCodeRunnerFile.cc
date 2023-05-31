#include <iostream>
using namespace std;

double e(double x, double n)
{
    static double s;
    if (n == 0)
        return s;
    s = 1 + x * s / n;
    return e(x, n - 1);
}
double e1(double x, double n)
{
    double s = 1;
    double num = 1;
    double den = 1;
    for (int i = 1; i <= n; i++)
    {
        num = num * x;
        den = den * i;
        s = s + num / den;
    }
    return s;
}
int main()
{

    cout << e1(1, 10) << endl;
    return 0;
}