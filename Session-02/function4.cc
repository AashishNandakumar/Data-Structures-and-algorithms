// call by reference
#include <iostream>
using namespace std;
void swap(int &x, int &y) // formal parameters - these are references i.e, nickname of the original value
{
    int temp;
    temp = x;
    x  = y;
    y = temp;
}
int main()
{
    int a, b;
    a = 10;
    b = 20;
    swap(a, b); // actual parmeters
    cout << a << endl
         << b << endl;
}