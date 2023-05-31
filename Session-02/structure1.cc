#include <iostream>
using namespace std;

struct rectangle // defination
{
    int length;
    int breadth;
    char x;        // total size should be 9, but 12 ans...default for char also it gives 4 bytes but uses only 1 byte, i.e, padding of memory
};

int main()
{
    struct rectangle r1; // declaration
    r1 = {10, 5, 'a'};
    // cout << sizeof(r1);
    cout<<r1.breadth<<endl;
    cout<<r1.length<<endl;
    r1.length = 40;
    cout<<"area: "<<r1.breadth*r1.length<<endl;
    return 0;
}