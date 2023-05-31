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

void Defined_pair_method1(int arr[], int n)
{
    int i = 0, j = n - 1, k;
    printf("Enter the pre-defined sum: ");
    scanf("%d", &k);
    while (i < j)
    {
        if (arr[i] + arr[j] == k)
        {
            printf("%d + %d = %d\n", arr[i], arr[j], k);
            i++;
            j--;
        }
        else if (arr[i] + arr[j] < k)
            i++;
        else
            j--;
    }
}
void Defined_pair_method2(int arr[], int n)
{
    int i, j, k;
    printf("Enter the pre-defined sum: ");
    scanf("%d", &k);
    for (i = 0, j = n - 1; i < j;)
    {
        if (arr[i] + arr[j] == k)
        {
            printf("%d + %d = %d", arr[i], arr[j], k);
            i++;
            j--;
        }
        else if (arr[i] + arr[k] < k)
            i++;
        else
            j--;
    }
}

int main()
{
    int arr[20], n;
    Accept(arr, &n);
    Defined_pair_method1(arr, n);
    Defined_pair_method2(arr, n);

    return 0;
}