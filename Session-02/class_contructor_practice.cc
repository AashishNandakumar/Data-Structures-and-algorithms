#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle()
    {
        length = breadth = 0;
    }
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    int area()
    {
        return (length * breadth);
    }
    int perimeter()
    {
        return (2 * (length * breadth));
    }

    void set_length(int l)
    {
        length = l;
    }
    int get_length()
    {
        return length;
    }
    void set_breadth(int b)
    {
        breadth = b;
    }
    int get_breadth()
    {
        return breadth;
    }
    ~Rectangle()
    {
        cout << "destructor!!!" << endl;
    };
};

int main()
{

    Rectangle r(10, 5);
    cout << "Area: " << r.area() << " "
         << "perimeter: " << r.perimeter() << endl;
}