#include <iostream>
using namespace std;
struct rectangle
{
    int length;
    int breadth;
};
void initialize(struct rectangle *r, int l, int b)
{
    r->length = l;
    r->breadth = b;
}

int area(struct rectangle r)
{
    return (r.breadth * r.length);
}

void change_length(struct rectangle *r, int l)
{
    r->length = l;
}
int main() // no process involved, only assigning work to other fxns
{
    struct rectangle r;        
    initialize(&r, 10, 5);
    area(r);
    change_length(&r, 20);
    return 0;
}