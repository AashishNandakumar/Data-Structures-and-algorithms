#include <iostream>
using namespace std;

// in c++ -> class and structure are same - structure is by default public and class is private.
class rectangle
{
private:
    int length;
    int breadth;

public:
    void initialize(int l, int b)
    {
        length = l;
        breadth = b;
    }

    int area()
    {
        return (breadth * length);
    }

    int peri()
    {
        return (2 * (breadth + length));
    }
};

int main()
{
    rectangle r;
    int l, b;
    // cout << "Enter length and breadth: ";
    // cin >> r.length >> r.breadth;

    r.initialize(5, 5);
    int a = r.area();
    int p = r.peri();

    cout << "The area : " << a << " "
         << "perimeter: " << p;

    return 0;
}