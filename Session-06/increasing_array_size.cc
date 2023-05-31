#include <iostream>
using namespace std;

int main()
{
    int *p, *q;
    p = new int[5];
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 5;
    p[4] = 6;
    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    q = new int[10];
    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }
    delete[] p;
    p = q;
    q = NULL;
    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}