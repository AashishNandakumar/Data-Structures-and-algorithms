#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter size: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(sizeof(int) * st->size);
}

void display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        printf("%d\n", st.S[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    if (st->top != -1)
    {
        int ele = st->S[st->top--];
        return ele;
    }
    else
        printf("Stack underflow\n");
}

int peek(struct Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("Invalid index");
    x = st.S[st.top - index + 1]; // A mathematical function

    return x;
}

int isEmpty(struct Stack st)
{
    return st.top == -1;
}

int isFull(struct Stack st)
{
    return st.top == st.size - 1;
}

int stackTop(struct Stack st)
{
    if (!isEmpty(st))
        return st.S[st.top];
    return -1;
}
int main()
{
    struct Stack st;
    //* TESTING
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    push(&st, 60);
    printf("At index 3: %d", peek(st, 3));
    printf("popping\n");
    printf("%d\n\n", pop(&st));
    printf("%d\n\n", pop(&st));
    display(st);
    return 0;
}