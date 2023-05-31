#include <iostream>
#include <stdio.h>

using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;

        Q = new Node *[size];
    }
    void enqueue(Node *x);
    Node *dequeue();
    int isEmpty() { return front == rear; }
};
void Queue::enqueue(Node *x)
{
    if (rear == size - 1)
        printf("Queue Full\n");
    else
    {
        rear++;
        Q[rear] = x;
    }
}
Node *Queue::dequeue()
{
    Node *x = NULL;
    if (front == rear)
        printf("Queue is Empty\n");
    else
    {

        x = Q[front + 1];
        front++;
    }
    return x;
}

// implementing Tree class
class Tree
{
public:
    Node *root;
    Tree() { root = NULL; }
    void createTree();
    void preOrder(Node *p);
    void inOrder(Node *p);
    void postOrder(Node *p);
    void levelOrder(Node *p);
    int height(Node *root);
};

void Tree::createTree()
{
    Node *p, *t = NULL;
    int x;
    Queue q(100);
    printf("Enter root value: ");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        printf("enter left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        printf("enter right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preOrder(struct Node *p)
{
    if (p)
    {

        printf("%d ", p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}
void Tree::inOrder(struct Node *p)
{
    if (p)
    {

        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}
void Tree::postOrder(struct Node *p)
{
    if (p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        printf("%d ", p->data);
    }
}

void Tree::levelOrder(struct Node *root)
{

    Queue q(100);
    printf("%d ", root->data);
    q.enqueue(root);
    while (!q.isEmpty())
    {
        root = q.dequeue();
        if (root->lchild)
        {
            printf("%d ", root->lchild->data);
            q.enqueue(root->lchild);
        }
        if (root->rchild)
        {
            printf("%d ", root->rchild->data);
            q.enqueue(root->rchild);
        }
    }
}
int Tree::height(struct Node *root)
{

    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int main()
{
    Tree t;
    t.createTree();
    cout << "Preorder ";
    t.preOrder(t.root);
    cout << endl;
    cout << "Inorder ";
    t.inOrder(t.root);
    cout << endl
         << endl;
    return 0;
}