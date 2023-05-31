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

void display(struct array arr3)
{
    int i;
    cout << "Elements are: " << endl;
    for (int i = 0; i < arr3.length; i++)
    {
        cout << arr3.a[i] << " ";
    }
}

struct array *Union(struct array *arr1, struct array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct array *arr3 = (struct array *)malloc(sizeof(struct array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->a[i] < arr2->a[j])
            arr3->a[k++] = arr1->a[i];

        else if (arr2->a[j] < arr2->a[i])
            arr3->a[k++] = arr2->a[j++];

        else
        {
            arr3->a[k++] = arr1->a[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->a[k++] = arr1->a[i];

    for (; j < arr2->length; j++)
        arr3->a[k++] = arr2->a[j];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct array *Intersection(struct array *arr1, struct array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct array *arr3 = (struct array *)malloc(sizeof(struct array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->a[i] < arr2->a[j])
            i++;

        else if (arr2->a[j] < arr2->a[i])
            j++;

        else if (arr1->a[i] == arr2->a[j])
        {
            arr3->a[k++] = arr1->a[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct array *Difference(struct array *arr1, struct array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct array *arr3 = (struct array *)malloc(sizeof(struct array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->a[i] < arr2->a[j])
            arr3->a[k++] = arr1->a[i];

        else if (arr2->a[j] < arr2->a[i])
            j++;

        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->a[k++] = arr1->a[i];

    

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

int main()
{
    struct array arr1 = {{2, 3, 4, 5, 6}, 10, 5};
    struct array arr2 = {{6, 7, 8, 9, 10}, 10, 5};
    struct array *arr3;

    arr3 = Difference(&arr1, &arr2);

    display(*arr3);

    return 0;
}