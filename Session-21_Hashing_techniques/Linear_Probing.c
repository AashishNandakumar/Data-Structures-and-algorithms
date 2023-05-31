#include <stdio.h>
#define SIZE 10

int hash_function(int key)
{

    return key % SIZE;
}

//* NOTE: For quaratic probing replace i by --> i*i, this reduces primary clustering of keys
int linear_probe(int H[], int key)
{
    int index = hash_function(key);
    int i = 0;

    while (H[(index + i) % SIZE] != 0)
        i++;

    return (index + i) % SIZE;
}

void Insert(int H[], int key)
{
    int index = hash_function(key);

    if (H[index] != 0)
        index = linear_probe(H, key);

    H[index] = key;
}

int Search(int H[], int key)
{
    int index = hash_function(key);

    int i = 0;
    while (H[(index + i) % SIZE] != key)
        i++;
    return (index + i) % SIZE;
}

int main()
{
    int HT[10];
    for (int i = 0; i < 10; i++)
        HT[i] = 0;
    Insert(HT, 12);
    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 26);

    printf("Key found at: %d\n", Search(HT, 35));

    return 0;
}