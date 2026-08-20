#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

int n;
int front = 0;
int rear = 0;

void BFS(int start)
{
    int current, i;

    /* Mark starting vertex as visited */
    visited[start] = 1;

    /* Insert starting vertex into queue */
    queue[rear] = start;
    rear++;

    printf("BFS Traversal: ");

    /* Repeat until queue becomes empty */
    while (front < rear)
    {
        /* Remove vertex from queue */
        current = queue[front];
        front++;

        /* Print vertex */
        printf("%d ", current);

        /* Find all adjacent vertices */
        for (i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 &&
                visited[i] == 0)
            {
                /* Mark as visited */
                visited[i] = 1;

                /* Insert into queue */
                queue[rear] = i;
                rear++;
            }
        }
    }
}

int main()
{
    int i, j;
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    /* Initially all vertices are unvisited */
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    BFS(start);

    return 0;
}
