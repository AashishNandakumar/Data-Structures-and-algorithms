// operations on array
#include <iostream>
using namespace std;

struct array
{
    int *a;
    int size;   // -> tells the max units an array can store
    int length; // -> tells the current elements stored in an array
};

void display(struct array arr)
{
    int i;
    cout << "Elements are: " << endl;
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.a[i] << " ";
    }
}
int main()
{
    struct array arr;
    int n, i;

    cout << "Enter size of an array: ";
    cin >> arr.size;

    int size = arr.size;
    arr.a = new int[size];
    arr.length = 0;

    cout << "Enter how many numbers: ";
    cin >> n;

    cout << "Enter elements: " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr.a[i];
    }

    arr.length = n;

    display(arr);

    return 0;
}