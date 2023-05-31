// Generic classes -> what happens if two differnt data types are needed for calculation... so we use generic classes
#include <iostream>
using namespace std;

template <class T> // insted of int or any other data types use T
class arthimethic
{
private:
    T a;
    T b;

public:
    arthimethic(T a, T b);
    T add();
    T sub();
};

template <class T>
arthimethic<T>::arthimethic(T a, T b)
{
    this->a = a; // this -> for assighning the values to a class, pointer to a current object in c++
    this->b = b;
}

template <class T>
T arthimethic<T>::add()
{
    T c;
    c = a + b;
    return c;
}

template <class T>
T arthimethic<T>::sub()
{
    T c;
    c = a - b;
    return c;
}



int main()
{
    arthimethic<float> ar(10.5, 5.4);
    cout << "Add: " << ar.add() << " "
         << "Subtract: " << ar.sub() << endl;
    return 0;
}
