#include <iostream>
using namespace std;

class rectangle
{
private:
    int length;
    int breadth;

public:
    rectangle()
    {
        length = breadth = 1;
    }
    rectangle(int l, int b);
    int area();
    int perimter();
    int get_length()
    {
        return length;
    }
    void set_length(int l)
    {
        length = l;
    }

    ~rectangle(); // destructor
};

rectangle::rectangle(int l, int b)
{
    length = l;
    breadth = b;
}

int rectangle::area()
{
    return (length * breadth);
}

int rectangle::perimter()
{
    return (2 * (length + breadth));
}

// rectangle::~rectangle();  // :: -> scope resolution , to call fxns out of the class

int main()
{
    rectangle r(10, 5);
    cout << r.area();
    cout << r.perimter();
    r.set_length(20);
    r.get_length();
    return 0;
}