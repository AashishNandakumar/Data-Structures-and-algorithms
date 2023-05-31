#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;                                  // variable size array
    int a[n] = {2, 3, 4, 5, 6, 7, 8, 9, 0, 4}; // all elements will be zero
    for (int x : a)                            // for each loop
    {
        cout << x << endl;
    }
    return 0;
}