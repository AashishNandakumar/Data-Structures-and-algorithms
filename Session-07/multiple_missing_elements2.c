// ! Not working :(

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num, max, min;
    int l, h;
    int *ptr1, *ptr2;
    printf("Enter the number of elements of the array: ");
    scanf("%d", &num);
    ptr1 = (int *)malloc(sizeof(int) * num);
    printf("Enter the array elements(In any order): \n");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &ptr1[i]);
    }

    // to find the maximum element in an array
    max = ptr1[0];
    for (int i = 0; i < num; i++)
    {
        if (ptr1[i] > max)
            max = ptr1[i];
    }
    h = max;

    min = ptr1[1];
    for (int i = 0; i < num; i++)
    {
        if (ptr1[i] < min)
            min = ptr1[i];
    }
    l = min;

    ptr2 = (int *)malloc(sizeof(int) * (max+1));
    for (int i = 0; i < num; i++)
    {
        ptr2[ptr1[i]]++;
    }
    for (int i = l; i <= h; i++)
    {
        if (ptr2[i] == 0)
            printf("\nMissing elements: %d", i);
    }

    return 0;
}