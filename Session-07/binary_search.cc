// operations on array
#include <iostream>
using namespace std;

struct array
{
    int a[10];
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

int Binary_search(struct array arr, int key)
{
    int l, h, mid;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.a[mid])
            return mid;
        else if (key < arr.a[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int RBin_search(int a[], int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return RBin_search(a, l, mid - 1, key);
        else
            return RBin_search(a, mid + 1, h, key);
    }
    return -1;
}

int main()
{
    struct array arr = {{2, 3, 4, 5, 6}, 10, 5};
    display(arr);
    cout << endl;
    cout << RBin_search(arr.a, 0, arr.length, 90);

    return 0;
}