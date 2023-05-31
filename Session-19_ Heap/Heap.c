#include <stdio.h>

void Insert(int H[], int n)
{
    int i = n, temp;
    temp = H[i];

    while (i > 1 && temp > H[i / 2])
    {
        H[i] = H[i / 2];
        i /= 2;
    }
    H[i] = temp;
}

void display(int H[])
{
    for (int i = 1; i < 8; i++)
    {
        printf("%d ", H[i]);
    }
    printf("\n");
}

int Delete(int H[], int n)
{
    int i, j, x, delVal;

    delVal = H[1]; //* deleting the root node
    x = H[n];
    H[1] = H[n];
    // H[n] = delVal;
    i = 1;
    j = i * 2;

    while (j < n - 1)
    {
        if (H[j] < H[j + 1])
            j += 1;

        if (H[i] < H[j])
        {
            int temp = H[i];
            H[i] = H[j];
            H[j] = temp;

            i = j;
            j = i * 2;
        }
        else
            break;
    }
    return delVal;
}

int main()
{
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    //* 40, 25, 35, 10, 5, 20, 30 --> MAX Heap
    int heapSort[8];
    for (int i = 2; i < 8; i++)
    {
        Insert(H, i);
    }
    display(H);

    for (int i = 1; i < 8; i++)
    {
        heapSort[i] = Delete(H, i);
    }

    display(heapSort);

    return 0;
}