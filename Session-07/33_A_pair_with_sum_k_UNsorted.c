#include <stdio.h>
#include <stdlib.h>

int maximum(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void Accept(int arr[], int *n)
{
    printf("Enter the number of elements of the array: ");
    scanf("%d", n);
    printf("Enter the array elements: \n");
    for (int i = 0; i < *n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void A_defined_sum_unsorted(int arr[], int n) // !-> But too time consuming
{
    int k;
    printf("Enter the pre-defined sum: ");
    scanf("%d", &k);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                printf("%d + %d = %d\n", arr[i], arr[j], k);
            }
        }
    }
}

void A_defined_sum_unsorted_hashing(int arr[], int n)
{
    int k;
    printf("Enter the pre-defined sum: ");
    scanf("%d", &k);
    int max = maximum(arr, n);
    int *hash;
    hash = (int *)malloc(sizeof(int) * max);
    for (int i = 0; i <= max; i++) // -> for setting all the elements to 0
    {
        hash[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (hash[k - arr[i]] != 0)
            printf("%d + %d = %d", arr[i], k - arr[i], k);
        hash[arr[i]]++;
    }
}
int main()
{
    int arr[20], n;
    Accept(arr, &n);
    A_defined_sum_unsorted(arr, n);
}