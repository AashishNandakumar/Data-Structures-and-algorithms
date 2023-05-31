#include <iostream>
using namespace std;
struct rectangle
{
    int length;
    int breadth;
};
int area(struct rectangle r)
{
    return (r.breadth * r.length);
}

int peri(struct rectangle r)
{
    return (2 * (r.breadth + r.length));
}

void initialize(struct rectangle *r, int l, int b)
{
    r->length = l;
    r->breadth = b;
}

int main()
{
    rectangle r = {0, 0};
    int areas, perimeters;
    cout << "Enter length and breadth: ";
    cin >> r.length >> r.breadth;

    areas = area(r); // processing part
    perimeters = peri(r);

    cout << "The area : " << areas << " "
         << "perimeter: " << perimeters;

    return 0;
}