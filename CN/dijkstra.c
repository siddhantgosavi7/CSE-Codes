#include <stdio.h>

#define MAX 12

int graph[MAX][MAX] = {{0, 2, 0, 0, 9, 8, 0, 0, 0, 0, 0, 0},
                       {2, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 7, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
                       {0, 0, 0, 0,22, 0, 0,15, 0, 0, 0, 0},
                       {9, 0, 0,22, 0, 0,11, 0, 0, 0, 0, 0},
                       {8, 0, 0, 0, 0, 0,13, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0,11,13, 0, 0,17, 0, 0, 0},
                       {0, 0, 0,15, 0, 0, 0, 0, 6, 0, 0,15},
                       {0, 0, 0, 0, 0, 0,17, 6, 0, 0, 0,20},
                       {0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,17},
                       {0, 0, 0, 0, 0, 0, 0,15,20, 0,17, 0}};

int visited[MAX];
int dist[MAX];
int queue[MAX];

int n;
int front = 0;
int rear = 0;

void PrintGraph();
void PrintTable();

void BFS(int start)
{
    int current, i;

    // Mark starting vertex as visited 
    visited[start] = 1;

    // Insert starting vertex into queue 
    queue[rear] = start;
    rear++;

    dist[start] = 0;

    //printf("BFS Traversal: ");

    // Repeat until queue becomes empty 
    while (front < rear)
    {
        // Remove vertex from queue 
        current = queue[front];
        front++;

        // Print vertex 
        //printf("%d ", current);

        // Find all adjacent vertices 
        for (i = 0; i < MAX; i++)
        {
            if (graph[current][i] != 0 && visited[i] == 0) {
                // Mark as visited 
                //visited[i] = 1;

                // Insert into queue 
                queue[rear] = i;
                rear++;
                
                if(dist[i] > graph[current][i] + dist[current]) {
                    dist[i] = graph[current][i] + dist[current];
                }
            }

        }

        PrintTable();
    }
}



void PrintTable() {
    printf("Distance Table: ");
    for(int i=0; i<MAX; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");

    printf("Visited Table: ");
    for(int i=0; i<MAX; i++) {
        printf("%d ", visited[i]+1);
    }
    printf("\n");

    printf("Queue: ");
    for(int i=0; i<MAX; i++) {
        printf("%d ", queue[i]+1);
    }
    printf("\n\n");
}

void PrintGraph()
{
    int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int i, j;
    int start;

    /*
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }*/

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    /* Initially all vertices are unvisited */
    for (i = 0; i < MAX; i++)
    {
        visited[i] = 0;
        dist[i] = 100;
    }

    //PrintGraph();
    BFS(start-1);

    return 0;
}
