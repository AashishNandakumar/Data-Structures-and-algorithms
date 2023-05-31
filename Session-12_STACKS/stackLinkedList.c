#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("No space!!!");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    int x;
    if (top == NULL)
        printf("no elements to delete");
    else
    {

        struct Node *t;
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *t;
    t = top;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int isBalanced(char *exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            if (top == NULL)
                return 0;
            pop();
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else
        return 0;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

char *infixToPostfix(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc(sizeof(char) * (len + 2));

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (precedence(infix[i]) > precedence(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (top != '\0')
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    return postfix;
}

int evalPostfix(char *postfix)
{
    int i = 0, x1 = 0, x2 = 0, r = 0;
    for (i = 0; postfix[i] != '\0'; i++)
    {

        if (isOperand(postfix[i]))
        {
            // postfix[i] -= '0';  --> can't do it bcoz pointers can't be changed.
            push(postfix[i] - '0');
        }
        else
        {
            x2 = pop();
            x1 = pop();
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            case '^':
                r = pow(x1, x2);
                break;
            }
            push(r);
        }
    }
    return top->data;
}
int main()
{
    char *postfix = "22^";
    printf("res: %d", evalPostfix(postfix));
    return 0;
}