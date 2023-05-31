#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{

    int A[10] = {1, 2, 3, 4, 5};
    int *p;

    p = (int *)malloc(sizeof(int) * 5);
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 5;
    p[4] = 6;
    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << " ";
    }

    cout<< (int)&p[2] <<endl;
}