#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    int graph[20][20];
    int distance[20];
    int visited[20] = {0};
    int source;
    int i, j, count;
    int min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the weighted adjacency matrix:\n");
    printf("(Enter 0 if there is no direct road)\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INT_MAX;
        }
    }

    printf("Enter source vertex (1 to %d): ", n);
    scanf("%d", &source);

    source--;

    /* Initialize distances */
    for (i = 0; i < n; i++)
    {
        distance[i] = graph[source][i];
    }

    distance[source] = 0;
    visited[source] = 1;

    /* Dijkstra's algorithm */
    for (count = 1; count < n; count++)
    {
        min = INT_MAX;
        u = -1;

        /* Find the unvisited vertex with minimum distance */
        for (i = 0; i < n; i++)
        {
            if (!visited[i] && distance[i] < min)
            {
                min = distance[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        /* Update distances of adjacent vertices */
        for (j = 0; j < n; j++)
        {
            if (!visited[j] &&
                graph[u][j] != INT_MAX &&
                distance[u] != INT_MAX &&
                distance[u] + graph[u][j] < distance[j])
            {
                distance[j] = distance[u] + graph[u][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source + 1);

    for (i = 0; i < n; i++)
    {
        if (distance[i] == INT_MAX)
            printf("Destination %d : INF\n", i + 1);
        else
            printf("Destination %d : %d\n", i + 1, distance[i]);
    }

    return 0;
}