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

struct Node *sort(struct Node *first)
{
    struct Node *p = first;
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
    return first;
}
int main()
{
    int A[] = {13, 5, 70, 1, 15, 4, 56, 5, 700};

    create(A, 9);
    // display(first);
    // printf("\n");
    first = sort(first);
    Rdisplay(first); // displaying recursively

    return 0;
}