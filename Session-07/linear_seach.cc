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
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int ls(struct array arr, int key) // -> normal linear search
{
    int i;
    for (int i = 0; i < arr.length; i++)
    {
        if (key == arr.a[i])
            return i;
    }
    return -1;
}

int ls1(struct array *arr, int key) // -> transposition
{
    int i;
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->a[i])
        {
            swap(&arr->a[i], &arr->a[i - 1]);
            return i;
        }
    }
    return -1;
}

int ls2(struct array *arr, int key) // -> move to head
{
    int i;
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->a[i])
        {
            swap(&arr->a[i], &arr->a[0]);
            return i;
        }
    }
    return -1;
}

int main()
{
    struct array arr = {{2, 3, 4, 5, 6}, 10, 5};
    display(arr);
    cout << endl;
    int res = ls(arr, 6);

    return 0;
}