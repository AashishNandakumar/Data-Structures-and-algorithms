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
void Duplicate_unsorted(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int count = 1;
        if (arr[i] != -1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                    arr[j] = -1;
                }
            }
            if (count > 1)
                printf("%d is repeating %d times", arr[i], count);
        }
    }
}

void Duplicate_unsorted_Hashing(int arr[], int n)
{
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
    for (int i = 0; i <= max; i++)
    {
        if (hash[i] > 1)
            printf("%d is repeating %d times\n", i, hash[i]);
    }
}

int main()
{
    int arr[20], n;
    Accept(arr, &n);
    // Duplicate_unsorted(arr, n);
    Duplicate_unsorted_Hashing(arr, n);

    return 0;
}