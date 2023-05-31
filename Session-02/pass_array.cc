// array passing to a function
#include <iostream>
using namespace std;

void display(int a[], int n)    // or *a
{
    //cout << "modifying!!..." << endl;
    
    //a[1] = 35;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int a[5] = {2, 3, 4, 5, 6};
    display(a, 5);
    
}