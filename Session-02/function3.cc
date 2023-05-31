// Call by address
#include <iostream>
using namespace std;
void swap(int *x, int *y) // formal parameters - of type pointers
{
    int temp; // returns more than one value
    temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int a, b;
    a = 10;
    b = 20;
    swap(&a, &b); // actual parmeters - which passes addresss of the original values
    cout << a << endl
         << b << endl;
}