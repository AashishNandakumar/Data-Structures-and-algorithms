#include <iostream>
using namespace std;

int area(int l, int b)
{
    return (l * b);
}

int peri(int l, int b)
{
    return (2 * (l + b));
}

int main()
{
    static int length, breadth, areas, perimeters;
    cout << "Enter length and breadth: "; // user interaction
    cin >> length >> breadth;

    areas = area(length, breadth); // processing part
    perimeters = peri(length, breadth);

    cout << "The area : " << areas << " "
         << "perimeter: " << perimeters;

    return 0;
}