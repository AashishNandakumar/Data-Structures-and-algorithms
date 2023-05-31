// * Create and display a Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int a[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void Rdisplay(struct Node *p)
{
    if (p != NULL)
    {
        // Rdisplay(p->next);  // first recursion->will print data in reverse order
        printf("%d ", p->data); // then print
        Rdisplay(p->next);      // will print data in OG order
    }
}

int count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

int Rcount(struct Node *p)
{
    if (p)
        return Rcount(p->next) + 1;
    else
        return 0;
}

int Sum(struct Node *p)
{
    int s = 0;
    while (p)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

int RSum(struct Node *p)
{
    if (p)
        return RSum(p->next) + p->data;
    else
        return 0;
}


int main()
{
    int A[] = {3, 5, 7, 10, 15, 8, 12, 259};

    create(A, 8);
    // display(first);
    // Rdisplay(first); // displaying recursively
    // printf("length is : %d\n", count(first));
    // printf("length is : %d", Rcount(first));
    printf("Sum  : %d", Sum(first));
    printf("Sum  : %d", RSum(first));
    


    return 0;
}