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
void reverse1(struct array *arr) // auxilary array
{
    int *B;
    int i, j;
    B = (int *)malloc(arr->length * sizeof(int));
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->a[i];
    }
    for (i = 0; i < arr->length; i++)
    {
        arr->a[i] = B[i];
    }
}

void reverse2(struct array *arr)
{
    int i,j;
    int temp;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        temp = arr->a[i];
        arr->a[i] = arr->a[j];
        arr->a[j] = temp;
    }
}

int main()
{
    struct array arr = {{2, 3, 4, 5, 6}, 10, 5};
    reverse2(&arr);
    display(arr);

    return 0;
}