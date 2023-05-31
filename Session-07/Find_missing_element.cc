#include <stdio.h>
#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete[] A;
    }
    void Insert(int index, int x);
    void Display();
    int missing1(int num);
    int missing2(int num);
};

void Array::Insert(int index, int x)
{
    int i;
    if (index >= 0 && index <= length)
    {
        for (i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}

void Array::Display()
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < length; i++)
        printf("%d ", A[i]);
}

// ! This does't works
int Array ::missing1(int num)
{
    int s, res, sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += A[i];
    }
    s = (num * (num + 1)) / 2;
    res = (s - sum);

    return res;
}

// * This works
int Array ::missing2(int num)
{
    int l = A[0];
    int index = 0;
    int diff = l - index;
    for (int i = 0; i < num; i++)
    {

        if (A[i] - i != diff)
        {
            return (i + diff);
            break;
        }
    }
}
int main()
{
    Array *arr1;
    int ch, sz;
    int x, index;
    int num, res;
    printf("Enter Size of Array: ");
    scanf("%d", &sz);
    arr1 = new Array(sz);
    printf("Enter number of elements in the array u wanna store: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("Enter an index and element: ");
        scanf("%d %d", &index, &x);
        arr1->Insert(index, x);
    }
    arr1->Display();
    cout << endl;
    cout << "The missing element is : " << arr1->missing1(num) << endl;

    return 0;
}
