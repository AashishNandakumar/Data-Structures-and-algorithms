#include <iostream>
using namespace std;

class rectangle
{
private:
    int length;
    int breadth;

public:
    rectangle(int l, int b) // automatically initializes the fxn
    {
        length = l;
        breadth = b;
    }

    int area()
    {
        return (breadth * length);
    }

    void change_length(int l)
    {
        length = l;
    }
};

int main()
{
    rectangle r(10,5);
    //r.initialize(10, 5);
    r.area();
    r.change_length(20);
    return 0;
}