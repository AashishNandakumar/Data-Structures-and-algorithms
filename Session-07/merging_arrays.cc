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

struct array *merge(struct array *arr1, struct array *arr2)
{
    int i, j, k;
    struct array *arr3 = (struct array *)malloc(sizeof(struct array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->a[i] < arr2->a[j])
            arr3->a[k++] = arr1->a[i];
        else
            arr3->a[k++] = arr2->a[j++];


        for (; i < arr1->length; i++)
            arr3->a[k++] = arr1->a[i];

        for (; j < arr2->length; j++)
            arr3->a[k++] = arr2->a[j];

        arr3->length = arr1->length + arr2->length;
        arr3->size = 10;

        return arr3;
    }
}
int main()
{
    struct array arr1 = {{2, 3, 4, 5, 6}, 10, 5};
    struct array arr2 = {{3, 5, 7, 8, 9}, 10, 5};
    struct array *arr3;
    arr3 = merge(&arr1, &arr2);

    display(*arr3);

    return 0;
}