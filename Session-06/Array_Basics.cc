#include <iostream>
using namespace std;

int main()
{
    int A[5];
    int B[5] = {1, 2, 3, 4, 5};
    int C[10] = {2, 5, 6};
    int D[5] = {0};
    int E[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        cout << (int)&A[i] << endl;
    }
    return 0;
}