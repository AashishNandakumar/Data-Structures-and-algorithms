#include <iostream>
using namespace std;
struct rectangle
{
    int length;
    int breadth;
};

int main()
{
    rectangle *p;
    
    //p = (struct rectangle *)malloc(sizeof(struct rectangle)); // - in c
    p = new rectangle; // - in c++
    p->breadth = 7;
    p->length = 15;

    cout << p->breadth << endl
         << p->length << endl;

    return 0;
}