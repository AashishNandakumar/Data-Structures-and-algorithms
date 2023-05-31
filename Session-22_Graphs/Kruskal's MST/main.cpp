#include <iostream>
#define I INT16_MAX
using namespace std;

int edges[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                   {2, 6, 3, 7, 4, 5, 7, 6, 7},
                   {25, 5, 12, 10, 8, 16, 14, 20, 18}};

int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1}; // Array for finding cycle
int track[9] = {0};                            // Track edges that are included in solution
int T[2][6];                                   // Solution array

// Set operations: Union and Find
void Union(int u, int v)
{
    if (set[u] < set[v])
    {
        set[u] += set[v];
        set[v] = u;
    }
    else
    {
        set[v] += set[u];
        set[u] = v;
    }
}

int Find(int u)
{
    int x = u;
    int v = 0;

    while (set[x] > 0)
    {
        x = set[x];
    }

    while (u != x)
    {
        v = set[u];
        set[u] = x;
        u = v;
    }
    return x;
}

int main()
{
    int i = 0, j, k, u, v, min = I, n = 7, e = 9;

    while (i < n - 1)
    {
        min = I;
        for (j = 0; j < e; j++)
        {
            if (track[j] == 0 && edges[2][j] < min)
            {
                u = edges[0][j];
                v = edges[1][j];
                k = j;
                min = edges[2][j];
            }
        }

        if (Find(u) != Find(v))
        {
            T[0][i] = u;
            T[1][i] = v;
            Union(Find(u), Find(v));
            i++;
        }
        track[k] = 1;
    }

    for (i = 0; i < n - 1; i++)
    {
        cout << "(" << T[0][i] << ", " << T[1][i] << ")" << endl;
    }
    return 0;
}