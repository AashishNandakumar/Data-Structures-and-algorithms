#include <stdio.h>
#include "Queue.h"

//* Breadth first Search:
void BFS(int G[][7], int start, int n)
{
    int i = start, j;
    struct Node q;
    int Visited[7] = {0};

    printf("%d ", i);
    Visited[i] = 1;
    enqueue(i);

    while (!isEmpty())
    {
        i = dequeue();
        for (j = 1; j <= n; j++)
        {
            if (G[i][j] == 1 && Visited[j] == 0)
            {
                printf("%d ", j);
                Visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

//* Depth First Search(Recursive):
void Rec_DFS(int G[][7], int start, int n)
{
    static int Visited[7] = {0}; //* To make it available in every function call
    int j;

    if (Visited[start] == 0)
    {
        printf("%d ", start);
        Visited[start] = 1;

        for (j = 1; j <= n; j++)
        {
            if (G[start][j] == 1)
                Rec_DFS(G, j, n);
        }
    }
}

//* Depth First Search(Iterative):
void Ite_DFS(int G[][7], int start, int n)
{
    int Visited[7] = {0}; //* To keep track of visited vertices
    int stack[7];         //* To store vartices for future ref
    int top = -1;
    int j;

    stack[++top] = start;

    while (top != -1)
    {
        int vertex = stack[top--];

        if (Visited[vertex] == 0)
        {
            printf("%d ", vertex);
            Visited[vertex] = 1;

            for (j = n; j >= 1; j--)
            {
                if (G[vertex][j] == 1 && Visited[j] == 0)
                    stack[++top] = j;
            }
        }
    }
}

int main()
{
    // * Explicitly creating an adjacenecy matrix
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    BFS(G, 3, 7);
    printf("\n");
    Rec_DFS(G, 4, 7);
    printf("\n");
    Ite_DFS(G, 4, 7);
    return 0;
}