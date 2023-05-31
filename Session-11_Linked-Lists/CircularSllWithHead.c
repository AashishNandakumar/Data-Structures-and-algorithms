#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

void insertFront(struct Node *Head, int item)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->info = item;
    temp->link = Head->link;
    Head->link = temp;
}

void display(struct Node *Head)
{
    if (Head->link == Head)
    {
        printf("No elements\n");
        return;
    }
    struct Node *curr;
    curr = Head->link;
    while (curr != Head)
    {
        printf("%d ", curr->info);
        curr = curr->link;
    }
}

void insertRear(struct Node *Head, int ele)
{
    struct Node *temp, *curr;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->info = ele;
    curr = Head;
    while (curr->link != Head)
        curr = curr->link;
    temp->link = curr->link;
    curr->link = temp;
}

void deleteFront(struct Node *Head)
{
    struct Node *curr;
    if (Head->link == Head)
        printf("No elements to delete\n");
    else
    {
        curr = Head->link;
        printf("%d will be deleted from front\n", curr->info);
        Head->link = curr->link;
        free(curr);
    }
}

void deleteRear(struct Node *Head)
{
    struct Node *curr, *prev;
    if (Head->link == Head)
        printf("No elements to delete\n");
    else
    {
        curr = Head->link;
        prev = Head;
        while (curr->link != Head)
        {
            prev = curr;
            curr = curr->link;
        }
        printf("%d will be deleted from rear\n", curr->info);
        prev->link = curr->link;
        free(curr);
    }
}
int main()
{
    struct Node *Head;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->link = Head;

    insertFront(Head, 10);
    insertFront(Head, 20);
    insertFront(Head, 30);
    insertRear(Head, 40);
    insertRear(Head, 50);
    insertRear(Head, 60);

    display(Head);

    printf("\nDeleting some elements: \n");
    deleteFront(Head);
    deleteFront(Head);
    deleteRear(Head);
    deleteRear(Head);
    display(Head);
    int op;
    while (1)
    {
        printf("1: Insert front\n2: Insert Rear\n3: Delete Front\n4: Delete Rear\n5: display\n6: exit\n");
        printf("ur coice: ");
        scanf("%d", op);
        // switch (op)
        // {
        // case 1 : insertFront(Head);
        //     break;
        // case 2 : insertFront(Head);
        //     break;
        //     case 3 : insertFront(Head);
        //     break;
        //     case 4 : insertFront(Head);
        //     break;
        //     case 5 : insertFront(Head);
        //     break;

        // default:
        //     break;
        // }
    }
    return 0;
}