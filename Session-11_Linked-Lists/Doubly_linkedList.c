#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev; 
    int data;
    struct Node *next;
} *first = NULL;

void create(int a[], int n)
{
    struct Node *t, *last;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->prev = first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int length(struct Node *p)
{
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if (index < 0 || index > length(first))
        return;
    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;

        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;

        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int delete(struct Node *p, int index)
{
    struct Node *q;
    int x = -1, i;
    if (index < 1 || index > length(p))
        return -1;
    if (index == 1)
    {
        first = first->next;
        if (first)
            first->prev = NULL;
        x = p->data;
        free(p);
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p != NULL && p->next == NULL)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}

void Reverse(struct Node *p)
{
    struct Node *temp;
    while (p!=NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p->next == NULL)
            first = p;
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);
    Reverse(first);
    printf("Hey");
    // *delete (first, 0);
    // *insert(first, 0, 25);
    // *printf("Length: %d\n", length(first));
    display(first);
    return 0;
}