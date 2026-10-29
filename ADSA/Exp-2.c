
#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int n;

void BFS(int start) {
    int front = 0, rear = 0;
    int current, i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        current = queue[front++];
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

void DFS(int current) {
    int i;

    visited[current] = 1;
    printf("%d ", current);

    for (i = 0; i < n; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main(void) {
    int i, j, start;

    printf("Enter number of vertices (1-20): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);

        for (j = 0; j < n; j++) {
            if (scanf("%d", &graph[i][j]) != 1 ||
                (graph[i][j] != 0 && graph[i][j] != 1)) {
                printf("Invalid adjacency matrix input.\n");
                return 1;
            }
        }
    }

    printf("Enter starting vertex (0-%d): ", n - 1);
    if (scanf("%d", &start) != 1 || start < 0 || start >= n) {
        printf("Invalid starting vertex.\n");
        return 1;
    }

    BFS(start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}
