#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *llink;
    int info;
    struct Node *rlink;
};

struct Node *getNode()
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Heap memory full!!\n");
        exit(0);
    }
    return temp;
}

struct Node *insertFront(struct Node *First, int item)
{
    struct Node *temp;
    temp = getNode();
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = First;
    if (First != NULL)
        First->llink = temp;
    First = temp;
    return temp;
}

struct Node *insertRear(struct Node *First, int item)
{
    struct Node *temp, *curr;
    temp = getNode();
    temp->info = item;
    curr = First;
    if (curr == NULL)
    {
        temp->llink = temp->rlink = NULL;
        return temp;
    }
    while (curr->rlink != NULL)
        curr = curr->rlink;

    curr->rlink = temp;
    temp->llink = curr;
    temp->rlink = NULL;

    return First;
}

void display(struct Node *First)
{
    struct Node *curr;
    curr = First;
    if (curr == NULL)
    {
        printf("No elements to display!!!\n");
        return;
    }
    while (curr != NULL)
    {
        printf("%d ", curr->info);
        curr = curr->rlink;
    }
}

struct Node *deleteFront(struct Node *First)
{
    if (First == NULL)
    {
        printf("NO elements to display!!\n");
        return NULL;
    }
    printf("\n%d will be deleted\n", First->info);
    struct Node *curr;
    curr = First;
    First = First->rlink;
    free(curr);
    First->llink = NULL;

    return First;
}

struct Node *deleteRear(struct Node *First)
{
    if (First == NULL)
    {
        printf("No elements to display\n");
    }
    else if (First->rlink == NULL)
    {
        printf("\n%d will be deleted\n", First->info);
        free(First);
        return NULL;
    }
    struct Node *curr;
    curr = First;
    while (curr->rlink != NULL)
        curr = curr->rlink;

    printf("\n%d will be deleted\n", curr->info);
    curr->llink->rlink = NULL;
    free(curr);

    return First;
}
int main()
{
    struct Node *First;
    First = getNode();
    First = NULL;
    First = insertFront(First, 10);
    First = insertFront(First, 20);
    First = insertFront(First, 30);
    First = insertRear(First, 40);
    First = insertRear(First, 50);
    First = insertRear(First, 60);
    display(First);
    First = deleteFront(First);
    First = deleteRear(First);
    display(First);

    return 0;
}