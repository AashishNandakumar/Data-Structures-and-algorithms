// fuctions introduction - independent program modules designed according to user preferances
#include <iostream>
using namespace std;
int add(int a, int b) // prototype/ signature/ declaration of a fxn // the values taken by fxn = formal parameters
{
    int c = a + b;
    return (c); // defination / elobration of a fxn - the whole part
}
int main()
{
    int x, y, z;
    x = 10;
    y = 5;
    z = add(x, y); // fxn call  // the values which we are passing = actual parameters
    cout << "Sum: " << z;
}

// the values of actual parameters are copied into formal paramters