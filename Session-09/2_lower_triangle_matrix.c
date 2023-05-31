#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

// * -> for row major method
void set1(struct Matrix *m, int i, int j, int x)
{
    if (i >= j)
        m->A[i * (i - 1) / 2 + j - 1] = x;
}

int get1(struct Matrix m, int i, int j)
{
    if (i >= j)
        return m.A[i * (i - 1) / 2 + j - 1];
    else
        return 0;
}
void display1(struct Matrix m) // ! -> Showing garbage value
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i >= j)
                printf(" %d ", m.A[i * (i - 1) / 2 + j - 1]);
            else
                printf(" 0 ");
        }
        printf("\n");
    }
}

// * -> for coloumn major method
void set2(struct Matrix *m, int i, int j, int x)
{
    if (i >= j)
        m->A[m->n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] = x;
}

int get2(struct Matrix m, int i, int j)
{
    if (i >= j)
        return m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
    else
        return 0;
}
void display2(struct Matrix m) // ! -> Showing garbage value
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i >= j)
                printf(" %d ", m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j]);
            else
                printf(" 0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    int i, j, x;
    printf("Enter dimensions: ");
    scanf("%d", &m.n);
    m.A = (int *)malloc(sizeof(int) * m.n * (m.n + 1) / 2);

    printf("Enter all elements: \n");
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            set2(&m, i, j, x);
        }
    }
    printf("\n\n");
    display2(m);
    return 0;
}