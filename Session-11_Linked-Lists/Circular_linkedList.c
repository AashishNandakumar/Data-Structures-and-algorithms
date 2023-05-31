#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *Head;

void create(int a[], int n) // *   --> Important
{
    int i;
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = a[0];
    Head->next = Head;

    last = Head;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void recursive_display(struct Node *h)
{
    static int flag = 0;
    if (h != Head || flag == 0)
    {
        flag = 1;
        printf("%d ", h->data);
        recursive_display(h->next);
    }
    flag = 0;
}

void display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);
    printf("\n");
}

int Length(struct Node *h)
{
    int len = 0;
    do
    {
        len++;
        h = h->next;
    } while (h != Head);

    return len;
}

/*struct Node *sort(struct Node *Head)
{
    struct Node *p = Head;
    struct Node *temp;
    for (struct Node *i = p; i->next->next != NULL; i = i->next)
    {
        for (struct Node *j = i->next; j->next != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp->data = i->data;
                i->data = j->data;
                j->data = temp->data;
            }
        }
    }
    return Head;
}
*/
void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > Length(p))
        return;

    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if (Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            while (p->next != Head)
                p = p->next;
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
int Delete(struct Node *p, int index)
{
    struct Node *q;
    int i, x;
    if (index < 0 || index > Length(Head))
        return -1;

    if (index == 1)
    {
        while (p->next != Head)
            p = p->next;
        x = Head->data;
        if (Head == p)
        {
            free(Head);
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}
void sort(struct Node *Head)
{
    struct Node *p = Head;
    struct Node *temp;
    for (struct Node *i = p; i->next != Head; i = i->next)
    {
        for (struct Node *j = i->next; j != Head; j = j->next)
        {
            if (i->data > j->data)
            {
                temp->data = i->data;
                i->data = j->data;
                j->data = temp->data;
            }
        }
    }
}

int main()
{
    int a[] = {23, 4, 45, 67, 4, 56, 24, 15, 14, 66, 88, 9, 10};
    create(a, 13);
    // int x = Delete(Head, 4);
    // printf("%d\n", x);
    //  insert(Head, 0, 10);
    display(Head);
    printf("Length of list: %d", Length(Head));
    printf("\n");

    // sort(Head);
    // display(Head);

    AddressSort(Head);
    display(Head);
    // *recursive_display(Head);
    return 0;
}