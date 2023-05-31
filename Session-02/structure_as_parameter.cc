// Structure as a paramter - call by value
#include <iostream>
using namespace std;

struct rectangle
{
    int length;
    int breadth;
};
int area(struct rectangle *r1, int l)  // just r1 -> for call by value  // &r1 -> for call by reference
{
    r1->length = l;
}
int main()
{
    struct rectangle r = {10, 5};
    area(&r, 20);
    cout<<r.length;

    return 0;
}