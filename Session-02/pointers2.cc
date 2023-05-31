// referencing
#include <iostream>
using namespace std;

int main()
{
    int a = 30; // created in stack
    int &r = a; // while declaring u need to initialize
    int b = 30;
    r = b;
    cout << a << endl
         << r << endl;

    return 0;
}