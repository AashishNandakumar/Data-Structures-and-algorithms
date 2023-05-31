#include <iostream>
using namespace std;

template <class T>

class Array
{
private:
    T *A;
    int size;
    int length;

public: // member fxns
    Array()
    {
        size = 10;
        A = new T[10];
        length = 0;
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new T[size];
    }
    ~Array() //  destructor
    {
        delete[] A;
    }
    void display(); // -> fxn prototyping
    void Insert(int index, T x);
    T Delete(int index);
}; // -> effect of template ends here

template <class T>
void Array<T>::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
template <class T>
void Array<T>::Insert(int index, T x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length - 1; i >= index; i--)
        {
            A[i + 1] = A[i];
        }
        A[index] = x;
        length++;
    }
}
template <class T>
T Array<T>::Delete(int index)
{
    int x = 0;
    if (index >= 0 && index <= length)
    {
        x = A[index];
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
    return x;
}

int main()
{
    Array<char> arr(10);

    arr.Insert(0, 'a');
    arr.Insert(1, 'b');
    arr.Insert(2, 'c');
    arr.Insert(3, 'd');
    arr.Insert(4, 'e');
    arr.display();
    cout << arr.Delete(0) << endl;
    arr.display();

    return 0;
}