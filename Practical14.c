#include <stdio.h>

#define MAX 20
#define INF 99999

struct District
{
    int beneficiaries;
    int severity;
    int demand;
    int distance;
    float priority;
    int allocated;
};

int graph[MAX][MAX];
int n;

/* Dijkstra's Algorithm */
void dijkstra(int source, int dist[])
{
    int visited[MAX] = {0};
    int i, j, min, u;

    for (i = 0; i < n; i++)
        dist[i] = graph[source][i];

    dist[source] = 0;
    visited[source] = 1;

    for (i = 1; i < n; i++)
    {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++)
        {
            if (!visited[j] &&
                graph[u][j] != INF &&
                dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
}

/* Sort districts according to priority */
void sortDistricts(struct District d[], int count)
{
    int i, j;
    struct District temp;

    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (d[j].priority < d[j + 1].priority)
            {
                temp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int roads, warehouse;
    int i, j;
    int u, v, cost, status;
    int totalResources;
    int weather;
    int dist[MAX];

    struct District d[MAX];

    int totalBeneficiaries = 0;
    int totalCost = 0;

    printf("Enter number of districts: ");
    scanf("%d", &n);

    printf("Enter warehouse district (0 to %d): ", n - 1);
    scanf("%d", &warehouse);

    /* Initialize graph */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    printf("\nEnter number of roads: ");
    scanf("%d", &roads);

    printf("\nEnter roads:\n");
    printf("Source Destination Cost Status\n");
    printf("Status: 1 = Working, 0 = Damaged\n");

    for (i = 0; i < roads; i++)
    {
        scanf("%d %d %d %d", &u, &v, &cost, &status);

        if (status == 1)
        {
            graph[u][v] = cost;
            graph[v][u] = cost;
        }
    }

    printf("\nEnter available resources: ");
    scanf("%d", &totalResources);

    printf("\nEnter weather condition:\n");
    printf("1 = Normal\n");
    printf("2 = Bad\n");
    printf("3 = Severe\n");
    scanf("%d", &weather);

    /* Input district information */
    for (i = 0; i < n; i++)
    {
        if (i == warehouse)
        {
            d[i].beneficiaries = 0;
            d[i].severity = 0;
            d[i].demand = 0;
            continue;
        }

        printf("\nDistrict %d\n", i);

        printf("Beneficiaries: ");
        scanf("%d", &d[i].beneficiaries);

        printf("Severity (1-10): ");
        scanf("%d", &d[i].severity);

        printf("Required resources: ");
        scanf("%d", &d[i].demand);
    }

    /* Find shortest paths */
    dijkstra(warehouse, dist);

    /* Calculate priority */
    for (i = 0; i < n; i++)
    {
        if (i == warehouse || dist[i] == INF)
        {
            d[i].priority = -1;
            continue;
        }

        d[i].distance = dist[i];

        /* Weather increases transportation cost */
        float weatherCost = dist[i];

        if (weather == 2)
            weatherCost = dist[i] * 1.5;

        else if (weather == 3)
            weatherCost = dist[i] * 2.0;

        d[i].priority =
            ((float)d[i].severity * d[i].beneficiaries)
            / weatherCost;
    }

    /* Sort by priority */
    sortDistricts(d, n);

    printf("\n========== RELIEF ALLOCATION ==========\n");

    for (i = 0; i < n; i++)
    {
        if (d[i].priority <= 0)
            continue;

        if (totalResources <= 0)
            break;

        if (d[i].demand <= totalResources)
            d[i].allocated = d[i].demand;
        else
            d[i].allocated = totalResources;

        totalResources -= d[i].allocated;

        totalBeneficiaries += d[i].beneficiaries;

        totalCost += d[i].distance;

        printf("\nDistrict served: %d", i);
        printf("\nSeverity: %d", d[i].severity);
        printf("\nPriority: %.2f", d[i].priority);
        printf("\nResources allocated: %d", d[i].allocated);
        printf("\nTransportation cost: %d", d[i].distance);
        printf("\n");
    }

    printf("\n========== FINAL RESULT ==========\n");

    printf("Total beneficiaries served: %d\n",
           totalBeneficiaries);

    printf("Total transportation cost: %d\n",
           totalCost);

    printf("Remaining resources: %d\n",
           totalResources);

    return 0;
}