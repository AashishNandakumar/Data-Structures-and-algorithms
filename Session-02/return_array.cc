// returning an array from a function
#include <iostream>
using namespace std;

int *get(int size) // new shit
{
    int *p;
    // p = (int *)malloc(n*sizeof(int));  //-> in c
    p = new int[size];
    for (int i = 0; i < size; i++)
    {
        p[i] = i + 1;
    }

    return p;
}
int main()
{
    int *ptr, sz;
    sz = 10;
    ptr = get(sz);

    for (int i = 0; i < sz; i++)
    {
        cout << ptr[i] << " ";
    }
    return 0;
}