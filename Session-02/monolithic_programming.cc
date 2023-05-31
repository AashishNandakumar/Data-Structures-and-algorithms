#include <iostream>
using namespace std;

int main()
{
    int length = 0, breadth = 0;
    cout << "Enter length and breadth: ";
    cin >> length >> breadth;
    
    int area = length * breadth;
    int peri = 2 * (length * breadth);

    cout << "area: " << area << endl
         << "perimeter: " << peri << endl;

    return 0;
}