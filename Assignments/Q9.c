#include <stdio.h>

int main()
{
    int graph[20][20];
    int visited[20] = {0};
    int queue[20];
    int n, start;
    int front = 0, rear = -1;
    int i, j, current;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (1 to %d): ", n);
    scanf("%d", &start);

    start--;   // Convert to 0-based index

    visited[start] = 1;
    queue[++rear] = start;

    printf("BFS Traversal: ");

    while (front <= rear)
    {
        current = queue[front++];

        printf("%d ", current + 1);

        for (i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }

    printf("\n");

    return 0;
}