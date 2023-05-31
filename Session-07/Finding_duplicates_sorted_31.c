// for Sorted array
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
int minimum(int arr[], int n)
{
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
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
void Duplicate(int arr[], int n)
{
    int last_duplicate = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] == arr[i + 1]) && (arr[i] != last_duplicate))
        {
            printf("\nRepeating elements are: %d\n", arr[i]);
            last_duplicate = arr[i];
        }
    }
}
void Duplicate_with_times(int arr[], int n)
{
    int j;
    for (int i = 0; i < n - 1; i++)
    {
        j = i;
        if (arr[i] == arr[i + 1])
        {
            j = j + 1;
            while (arr[j] == arr[i])
            {
                j++;
            }
            printf("%d is appearing %d times\n", arr[i], j - i);
            i = j - 1;
        }
    }
}
void Duplicate_with_times_with_Hashing(int arr[], int n)
{
    int max = maximum(arr, n);
    int *hash;
    hash = (int *)malloc(sizeof(int) * max);
    for (int i = 0; i <= max; i++)
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
    // Duplicate(arr, n);
    // Duplicate_with_times(arr, n);
    Duplicate_with_times_with_Hashing(arr, n);

    return 0;
}