#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    void push(int x);
    int pop();
    void display();
};

void Stack::push(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "NO space";
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    int x;
    if (top == NULL)
        cout << "Stack is empty";
    else
    {

        Node *t;
        t = top;
        x = top->data;
        top = top->next;
        delete t;
    }
    return x;
}

void Stack::display()
{
    Node *t;
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main()
{
    Stack obj;

    obj.push(10);
    obj.push(20);
    obj.push(30);

    obj.display();

    cout << obj.pop() << endl;
}