#include <stdio.h>

struct Edge
{
    int u, v, w;
};

int parent[20];

int find(int x)
{
    while (parent[x] != x)
        x = parent[x];

    return x;
}

void unionSet(int a, int b)
{
    parent[find(a)] = find(b);
}

int main()
{
    int n, e, i, j;
    int total = 0, count = 0;
    struct Edge edge[50], temp;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");

    for (i = 0; i < e; i++)
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);

    // Sort edges by weight
    for (i = 0; i < e - 1; i++)
    {
        for (j = 0; j < e - i - 1; j++)
        {
            if (edge[j].w > edge[j + 1].w)
            {
                temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }

    // Initially every vertex is its own parent
    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (i = 0; i < e && count < n - 1; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;

        if (find(u) != find(v))
        {
            printf("%d - %d : %d\n", u, v, edge[i].w);

            total += edge[i].w;
            unionSet(u, v);
            count++;
        }
    }

    printf("Minimum Cost = %d\n", total);

    return 0;
}