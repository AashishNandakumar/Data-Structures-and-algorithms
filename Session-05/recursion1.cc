#include <iostream>
using namespace std;
void fun(int n)
{
    if (n > 0)
    {
        cout << "k" << endl;
        fun(n - 1);
        cout << n << " ";
        
    }
}
int main()
{
    int x = 3;
    fun(x);
    return 0;
}