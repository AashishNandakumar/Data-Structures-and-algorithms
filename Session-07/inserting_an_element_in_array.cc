// operations on array
#include <iostream>
#include <stdlib.h>
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
    int temp = *x;
    *x = *y;
    *y = temp;
}
void InsertSort(struct array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;

    while (i >= 0 && arr->a[i] > x)
    {
        arr->a[i + 1] = arr->a[i];
        i--;
    }
    arr->a[i + 1] = x;
    arr->length++;
}

int sorted_or_not(struct array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.a[i] > arr.a[i + 1])
            return 0;
    }
    return 1;
}

void rearranging(struct array *arr)
{
    int i = 0, j = arr->length - 1;
    while (i < j)
    {
        while (arr->a[i] < 0)
        {
            i++;
        }
        while (arr->a[j] > 0)
        {
            j++;
        }
        if (i < j)
        {
            swap(&arr->a[i], &arr->a[j]);
        }
    }
}
int main()
{
    struct array arr = {{1,2,3,4,-3,-4,-3}, 10, 5};
    rearranging(&arr);
    display(arr);

    return 0;
}