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

int Gets(struct array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.a[index];
    return -1;
}

void Sets(struct array *arr, int index, int news)
{
    if (index >= 0 && index < arr->length)
        arr->a[index] = news;
}

int max(struct array arr)
{
    int max = arr.a[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.a[i] > max)
            max = arr.a[i];
    }

    return max;
}

int min(struct array arr)
{
    int min = arr.a[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.a[i] < min)
            min = arr.a[i];
    }

    return min;
}

int Sum(struct array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.a[i];
    }
    return sum;
}

float avg(struct array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.a[i];
    }
    return (float)sum / arr.length;
}

int main()
{
    struct array arr = {{2, 3, 4, 5, 6}, 10, 5};
    display(arr);
    cout << endl;
    cout << avg(arr) << endl;

    return 0;
}