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

void deletes(struct array *arr, int index)
{
    if (index >= 0 && index < arr->length)
    {

        for (int i = index; i < arr->length-1; i++)
        {
            arr->a[i] = arr->a[i + 1];
        }
        arr->length--;
    }
}

int main()
{
    struct array arr = {{2, 3, 4, 5, 6}, 10, 5};
    display(arr);

    deletes(&arr, 2);
    cout << "modified..." << endl;
    display(arr);

    return 0;
}