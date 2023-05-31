#include <stdio.h>

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

void Max_and_min(int arr[], int n)
{
    int min = arr[0], max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }

    printf("%d is the largest element\n", max);
    printf("%d is the smallest element\n", min);
}

int main()
{
    int arr[20], n;
    Accept(arr, &n);
    Max_and_min(arr, n);
    return 0;
}