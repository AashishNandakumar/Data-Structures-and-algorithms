#include <iostream>
using namespace std;
//* -> For row - major method only
class Lower_triangular
{
private:
    int *A;
    int n;

public:
    Lower_triangular() // non parameterized constructor
    {
        n = 2;
        A = new int[2 * (2 + 1) / 2];
    }
    Lower_triangular(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    ~Lower_triangular()
    {
        delete[] A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void display();
    int get_dimension()
    {
        return n;
    }
};

void Lower_triangular ::Set(int i, int j, int x)
{
    if (i >= j)
        A[i * (i - 1) / 2 + j - 1] = x;
}
int Lower_triangular ::Get(int i, int j)
{
    if (i >= j)
        return A[i * (i - 1) / 2 + j - 1];
    else
        return 0;
}

void Lower_triangular ::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << A[i * (i - 1) / 2 + j - 1] << " ";
            else
                cout <<"0 ";
        }
        cout << endl;
    }
}

int main()
{
    int d;
    cout << "Enter dimensions: ";
    cin >> d;

    Lower_triangular lm(d);

    int x;
    cout << "Enter all elements: " << endl;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            lm.Set(i, j, x);
        }
    }
    lm.display();

    return 0;
}