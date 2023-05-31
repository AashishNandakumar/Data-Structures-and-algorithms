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

void append(struct array *arr, int x)
{
    if (arr->length < arr->size)
        arr->a[arr->length++] = x;
}

void insert(struct array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {

        for (int i = arr->length; i > index; i--)
        {
            arr->a[i] = arr->a[i - 1];
        }
        arr->a[index] = x;
        arr->length++;
    }
}
int main()
{
    struct array arr = {{2, 3, 4, 5, 6}, 10, 5};
    display(arr);
    cout << endl;
    // append(&arr, 10);
    insert(&arr, 2, 10);
    display(arr);

    return 0;
}