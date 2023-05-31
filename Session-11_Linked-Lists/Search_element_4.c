// * Create and display a Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

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
void create2(int a[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = a[0];
    second->next = NULL;
    last = second;

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

int maximum(struct Node *p)
{
    int max = -32768;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int Rmaximum(struct Node *p)
{
    int x = 0;
    if (p == 0)
        return -32768;
    x = Rmaximum(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}

struct Node *Lsearch(struct Node *p, int key) // fxn returns Node type pointer
{
    while (p)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node *Rsearch(struct Node *p, int key)
{
    if (!p)
        return NULL;
    if (key == p->data)
        return p;
    return Rsearch(p->next, key);
}

struct Node *Msearch(struct Node *p, int key) // fxn returns Node type pointer
{
    struct Node *q;
    while (p)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return first;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if (index < 0 || index > count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL) // if linked list is empty
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first) // if element to be inserted is less than first element
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1;

    if (index < 1 || index > count(p)) // checks if the index given is valid or not
        return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {

        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
    }
    return x;
}

int isSorted(struct Node *p)
{
    int x = -32768;
    while (p)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next; // makes q point on 2nd element

    while (q)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void Reverse1(struct Node *p) // *only swap elements, using array
{
    int *a;
    a = (int *)malloc(sizeof(int) * count(p));
    struct Node *q = p;
    int i = 0;
    while (q)
    {
        a[i++] = q->data;
        q = q->next;
    }
    q = p;
    i--;
    while (q)
    {
        q->data = a[i--];
        q = q->next;
    }
}

void Reverse2(struct Node *p) // *swap links, by sliding pointers
{
    struct Node *q = NULL, *r = NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Reverse3(struct Node *q, struct Node *p) // *recursive swap, swapping links
{
    if (p)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
        first = q;
}
void concat(struct Node *p, struct Node *q)
{
    third = p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void merge(struct Node *p, struct Node *q) // works on 2 sorted lists
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    else
        last->next = q;
}

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : NULL;
    } while (p && q && p != q);

    return (p == q ? 1 : 0); 
}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    struct Node *t1, *t2;
    create(A, 5);
    // int B[] = {5, 159, 256, 355, 453};
    t1 = first->next->next; // * ur making a loop explicitly
    t2 = first->next->next->next->next;
    t2->next = t1;
    // struct Node *temp;
    printf("%d\n", isLoop(first));
    // create2(B, 5);

    // concat(first, second);
    // merge(first, second);
    // printf("concated\n");
    // display(third);
    // Reverse3(NULL,first);
    // RemoveDuplicate(first);
    // printf("%d\n", isSorted(first));
    // Insert(first, 0, 1);
    // Insert(first, 1, 2);
    // Insert(first, 2, 3);
    // Insert(first, 3, 4);
    // Insert(first, 4, 5);
    // Insert(first, 5, 6);
    // Insert(first, 2, 143);
    // SortedInsert(first, 55);
    // SortedInsert(first, 25);
    // printf("deleted element: %d\n", delete (first, 1));
    // Rdisplay(first); // displaying recursively
    // printf("length is : %d\n", count(first));
    // printf("length is : %d", Rcount(first));
    // printf("Sum  : %d", Sum(first));
    // printf("Sum  : %d", RSum(first));
    // printf("Maximum element : %d\n", maximum(first));
    // printf("Maximum element : %d", Rmaximum(first));
    // temp = Msearch(first, 259);
    // if (temp)
    //     printf("key found %d\n", temp->data);
    // else
    //     printf("key not found\n");

    // display(first);//->now 259 will be bought into first

    return 0;
}