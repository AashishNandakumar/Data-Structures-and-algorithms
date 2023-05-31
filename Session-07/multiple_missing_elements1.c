#include <stdio.h>
#include<stdlib.h>
int main()
{
    int num, diff = 0;
    int *ptr;
    printf("Enter the number of elements of array: ");
    scanf("%d", &num);

    ptr = (int *)malloc(sizeof(int)*num);

    printf("Enter array elements(in a sorted way) : \n");
    for(int i=0;i<num;i++)
    {
        scanf("%d", &ptr[i]);
    }
    
    diff = ptr[0] - 0;
    for(int i=0;i<num;i++)
    {
        if(ptr[i]-i!=diff)
        {
            while(diff<ptr[i]-i)
            {
                printf("\nMissing elemnts are: %d", i+diff);
                diff++;
            }
        }
    }
    return 0;
}