#include <iostream>
using namespace std;
struct rectangle
{
    int length;
    int breadth;
};
struct rectangle *fun()
{
    struct rectangle *p;
    p = new rectangle; //-> in c++

    p->length = 15;
    p->breadth = 7;

    return p;
}

int main()
{
    struct rectangle *ptr = fun();
    cout<<"length: "<<ptr->length<<" "<<"Breadth: "<<ptr->breadth<<endl;
    return 0;
}