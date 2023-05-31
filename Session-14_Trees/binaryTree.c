#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q; // bcoz it is an array + stores address
};
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}
void enqueue(struct Queue *q, struct Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is Full");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}
struct Node *dequeue(struct Queue *q)
{
    struct Node *x = NULL;

    if (q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}

struct Node *root = NULL;

void Tcreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
void preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data); // recursive bactracking
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p)
{
    if (p)
    {

        preorder(p->lchild);
        printf("%d ", p->data);
        preorder(p->rchild);
    }
}
void postorder(struct Node *p)
{
    if (p)
    {

        preorder(p->lchild);
        preorder(p->rchild);
        printf("%d ", p->data);
    }
}

/* void IPreorder(struct Node *p)     --> implement a stack
{
    struct Stack stk;
    StackCreate(&stk, 100);

    while(p||!isEmpty(stk))
    {
        if(p)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p=p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}
*/
/* void IInorder(struct Node *p)
{
    struct Stack stk;
    StackCreate(&stk, 100);

    while(p||!isEmpty(stk))
    {
        if(p)
        {
            push(&stk, p);
            p=p->lchild;
        }
        else
        {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}
*/

void levelOrder(struct Node *p)
{
    struct Queue q;
    create(&q, 100);
    printf("%d ", p->data);
    enqueue(&q, p);
    while (!isEmpty(q))
    {
        p = dequeue(&q);
        if (p->lchild)
        {
            printf("%d ", p->lchild->data);

            enqueue(&q, p->lchild);
        }
        if (p->rchild)
        {
            printf("%d ", p->rchild->data);

            enqueue(&q, p->rchild);
        }
    }
}

int count(struct Node *root)
{
    if (root)
    {
        return count(root->lchild) + count(root->rchild) + 1;
    }
    return 0;
}

int height(struct Node *root)
{
    int x, y;

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
    Tcreate();
    printf("Level order : \n");
    levelOrder(root);
    printf("Number of nodes: %d\n", count(root));
    printf("Height: %d\n", height(root));
    return 0;
}