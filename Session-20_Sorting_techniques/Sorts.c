#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int A[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

//* For bubble sort
void Bubble_Sort(int A[], int n)
{
    int i, j, flag;

    for (i = 0; i < n - 1; i++) //* for pass
    {
        flag = 0;                       //* To make it adaptive;
        for (j = 0; j < n - 1 - i; j++) //* For comparison
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]); //* For swapping
                flag = 1;
            }
        }
        if (!flag) //* It means no swappings are done
            break; //* It means the elements are sorted
    }
}

//* For insertion sort
void Insertion_Sort(int A[], int n) //* Best suited for Linked list sorting
{

    int i, j, x;
    for (i = 1; i < n; i++) //* Assuming first element is already sorted
    {
        j = i - 1;
        x = A[i];
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j]; //* Shifting algorithm
            j--;
        }
        A[j + 1] = x; //* Insert at the vacant space after shifting
    }
}

//* For selection sort
void Selection_Sort(int A[], int n)
{
    int i, j, k;

    for (i = 0; i < n - 1; i++) //* for passes
    {
        for (j = k = i; j < n; j++) //* for comparision
        {
            if (A[j] < A[k])
                k = j;
        } //* At the end of the loop K will be pointing to the smallest element in the list
        swap(&A[i], &A[k]);
    }
}

//* For quick sort:
int partition(int A[], int l, int h)
{

    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot); //* continue until u get an element greater than pivot
        do
        {
            j--;
        } while (A[j] > pivot); //* continue until u get an element smaller or equal to pivot

        if (i < j)
            swap(&A[i], &A[j]);

    } while (i < j);

    swap(&A[l], &A[j]);

    return j;
}

void quick_Sort(int A[], int l, int h)
{

    int j; //* Pivot
    if (l < h)
    {
        j = partition(A, l, h);
        quick_Sort(A, l, j - 1); //* call on left side of pivot
        quick_Sort(A, j + 1, h); //* call on right side of pivot
    }
}

//* For merge sort
void Merge(int A[], int l, int mid, int h)
{
    int i, j, k;
    int B[h + 1];
    i = l;
    j = mid + 1;
    k = l;

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];

    for (i = l; i <= h; i++)
        A[i] = B[i];
}

void Iterative_MergeSort(int A[], int n)
{
    int i, l, mid, h, p;
    //* The variable p represents the size of the subarrays being merged in each pass

    for (p = 2; p <= n; p *= 2) //* for passes
    {
        for (i = 0; i + p - 1 < n; i += p) //* for sliding the list, taking two elements at a time
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, h);
        }
    }

    if (i < n)
        Merge(A, 0, (p / 2) - 1, n - 1);
}

void Recursive_MergeSort(int A[], int l, int h)
{

    if (l < h) //* To make sure atleast 2 elements are there
    {
        int mid = (l + h) / 2;
        Recursive_MergeSort(A, l, mid);
        Recursive_MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

//* Count sort:
int findMax(int A[], int n)
{
    int temp = -1;

    for (int i = 0; i < n; i++)
    {
        if (A[i] > temp)
            temp = A[i];
    }

    return temp;
}

void count_sort(int A[], int n)
{
    int max, i, j;
    max = findMax(A, n);

    int *c;
    c = (int *)malloc(sizeof(int) * (max + 1));

    for (i = 0; i < max + 1; i++)
        c[i] = 0;

    for (i = 0; i < n; i++)
        c[A[i]]++;

    i = j = 0;
    while (i < max + 1)
    {
        if (c[i] > 0)
        {
            A[j++] = i;
            c[i]--;
            ;
        }
        else
            i++;
    }
    free(c);
}

//* Shell sort:
void Shell_Sort(int A[], int n)
{

    int gap, i, j;

    for (gap = n / 2; gap >= 1; gap /= 2) //* Iterates over the gap sizes
    {
        for (i = gap; i < n; i++) //* Iterates over the elements in the subarray
        {
            int temp = A[i];
            j = i - gap;

            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j -= gap;
            }
            A[j + gap] = temp;
        }
    }
}

int main()
{

    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int B[] = {3, 7, 9, 10, 13, 14, 15}; //* Already sorted array
    int n = sizeof(A) / sizeof(A[0]);    //* Gives the no of elements in the array
    int m = sizeof(B) / sizeof(B[0]);
    //* Bubble_Sort(B, m);
    //* Insertion_Sort(A, n);
    //* Selection_Sort(A, n);
    //* quick_Sort(A, 0, n);
    //*  Iterative_MergeSort(A, n);
    //* Recursive_ MergeSort(A, 0, n - 1);
    //* count_sort(A, n);

    Shell_Sort(A, n);
    display(A, n);
    return 0;
}