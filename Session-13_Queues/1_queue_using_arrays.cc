#include <iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    int *Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    void enequeue(int x);
    int dequeue();
    void display();
};

void Queue ::enequeue(int x)
{
    if (rear == size - 1)
        cout << "FULL" << endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}
int Queue::dequeue()
{
    int x = -1;
    if (front == rear)
        cout << "Empty" << endl;
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}

void Queue::display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue q(5);

    q.enequeue(10);
    q.enequeue(20);
    q.enequeue(30);
    q.display();
    cout << q.dequeue() << endl;
}