#include <stdio.h>
#include <stdlib.h>

// defining a structure to hold all the values of polynomial
struct Poly
{
    int cf, px, py, pz;
    struct Poly *link;
};

typedef struct Poly *P;

// This function return a struct Poly with memeory allocation
P getnode()
{
    P temp;
    temp = (P)malloc(sizeof(struct Poly));
    if (temp == NULL)
    {
        printf("NO MEMORY\n"); // gets executed when heap memory is full
        exit(0);
    }
    return temp;
}

void read_poly(P p1, int n)
{
    P temp;
    int i;
    for (i = 0; i < n; i++)
    {
        temp = getnode();
        printf("Enter the values of cf, px, py, pz: ");
        scanf("%d %d %d %d", &(temp->cf), &(temp->px), &(temp->py), &(temp->pz));
        temp->link = p1->link;
        p1->link = temp;
    }
}

void display(P p)
{
    printf("HERE - 1");
    P curr;
    int flag = 0;
    curr = p->link;
    printf("Displaying polynomial: \n");
    while (curr != p)
    {
        if (curr->cf >= 0)
        {
            printf("+");
            printf(" %d(X)^%d(Y)^%d(Z)^%d ", curr->cf, curr->px, curr->py, curr->pz);
        }

        else
            printf(" %d(X)^%d(Y)^%d(Z)^%d ", curr->cf, curr->px, curr->py, curr->pz);
        flag++;
        curr = curr->link;
    }
    printf("HERE - 1");
    printf("\n");
    if (!flag)
        printf("Empty polynomial extression!!!\n");
}
P Compare(P term, P p2)
{

    P curr;
    curr = p2->link;
    while (curr != p2)
    {
        if (curr->px == term->px && curr->py == term->py && curr->pz == term->pz)
            return curr;

        curr = curr->link;
    }
    return NULL;
}

void add(P res, P temp)
{
    temp->link = res->link;
    res->link = temp;
}

int main()
{
    P p1, p2;
    int n1, n2;
    p1 = getnode();
    p1->link = p1; // making circular sll in the main function
    printf("Enter number of terms of polynomial expression-1: ");
    scanf("%d", &n1);
    read_poly(p1, n1);
    // display(p1);

    p2 = getnode();
    p2->link = p2;
    printf("Enter number of terms of polynomial expression-2: ");
    scanf("%d", &n2);
    read_poly(p2, n2);
    // display(p2);

    P curr, res, temp;
    res = getnode();
    res->link = res;
    temp = getnode();
    curr = p1->link;
    while (curr != p1)
    {

        if (Compare(curr, p2) == NULL)
        {
            temp = curr;
            temp->cf = curr->cf;
        }
        else
        {
            temp = Compare(curr, p2);
            temp->cf = curr->cf + p2->cf;
        }
        add(res, temp);
    }

    display(res);
}
