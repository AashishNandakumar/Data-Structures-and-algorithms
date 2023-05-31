#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

struct Emp
{
    int id;
    char name[20];
    float salary;
};

struct Node
{
    struct Node *llink;
    struct Emp *E;
    struct Node *rlink;
};

struct Node *getnode()
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->E = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL || temp->E == NULL)
    {
        printf("No memeory");
        exit(0);
    }
    return temp;
}

struct Node *insertFront(struct Node *first)
{
    struct Node *temp;
    temp = getnode();
    printf("enter Employee id: ");
    scanf("%d", &(temp->E)->id);
    printf("Enter employee name: ");
    scanf("%s", (temp->E)->name);
    printf("Enter employee salary :");
    scanf("%f", &(temp->E)->salary);

    temp->llink = NULL;
    temp->rlink = first;
    if (first != NULL)
        first->llink = temp;

    return temp;
}

void getSalary(struct Node *first)
{
    float max = -1;
    char name[20];
    int id;
    struct Node *curr;
    curr = first;
    while (curr != NULL)
    {
        if ((curr->E)->salary > max)
        {
            max = (curr->E)->salary;
            strcpy(name, (curr->E)->name);
            id = (curr->E)->id;
        }
        curr = curr->rlink;
    }
    printf("displaying information of employee with greatest salary: \n");
    printf("name: %s\n", name);
    printf("id: %d\n", id);
    printf("salary: %f\n", max);
}

void seachName(struct Node *first)
{
    struct Node *curr;
    curr = first;
    printf("Displaying names which start with letter A: ");
    while (curr != NULL)
    {
        if ((curr->E)->name[0] == 'A')
        {
            printf("name: %s\n", curr->E->name);
            printf("id: %d\n", curr->E->id);
            printf("salary: %f\n", curr->E->salary);
        }
        curr = curr->rlink;
    }
}

struct Node *nameUpdate(struct Node *first)
{
    int id;
    char name[20];
    printf("Enter id to update: ");
    scanf("%d", &id);
    struct Node *curr;
    curr = first;
    while (curr != NULL)
    {
        if (curr->E->id == id)
        {
            printf("Enter name to replace: ");
            scanf("%s", name);
            strcpy(curr->E->name, name);
            printf("Name updated\n");
            return first;
        }
        curr = curr->rlink;
    }
    printf("No records for the given id\n");
    return first;
}

void display(struct Node *first)
{
    struct Node *curr;
    curr = first;
    int flag = 0;
    printf("Displaying info :\n");
    while (curr != NULL)
    {
        printf("name: %s\n", curr->E->name);
        printf("id: %d\n", curr->E->name);
        printf("salary: %f\n", curr->E->salary);
        flag++;
    }
    if (flag == 0)
        printf("No elements\n");
}

int main()
{
    struct Node *first;
    first = getnode();
    first = NULL;
    int op;

    while (1)
    {

        printf("1: insert\n2 :greatest salary\n3: Search name\n4: nameUpdate\n5: display\n6: exit\n");
        printf("ur choice: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            first = insertFront(first);
            break;
        case 2:
            getSalary(first);
            break;
        case 3:
            seachName(first);
            break;

        case 4:
            first = nameUpdate(first);
            break;
        case 5:
            display(first);
            break;
        case 6:
            exit(0);
        }
    }
    return 0;
}