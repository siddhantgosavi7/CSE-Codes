#include <stdio.h>

#include <stdlib.h>

struct Edge {

    int src, dest, weight;

};

int find(int parent[], int i) {

    if (parent[i] != i)

        parent[i] = find(parent, parent[i]);

    return parent[i];

}

void unionSets(int parent[], int rank[], int x, int y) {

    int rootX = find(parent, x);

    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY])

        parent[rootX] = rootY;

    else if (rank[rootX] > rank[rootY])

        parent[rootY] = rootX;

    else {

        parent[rootY] = rootX;

        rank[rootX]++;

    }

}

void sortEdges(struct Edge edges[], int E) {

    for (int i = 0; i < E - 1; i++) {

        for (int j = 0; j < E - i - 1; j++) {

            if (edges[j].weight > edges[j + 1].weight) {

                struct Edge temp = edges[j];

                edges[j] = edges[j + 1];

                edges[j + 1] = temp;

            }

        }

    }

}

void kruskalMST(struct Edge edges[], int V, int E) {

    sortEdges(edges, E);

    int *parent = (int*)malloc(V * sizeof(int));

    int *rank = (int*)malloc(V * sizeof(int));

    for (int v = 0; v < V; v++) {

        parent[v] = v;

        rank[v] = 0;

    }

    printf("Edges in the constructed MST:\n");

    printf("Edge \tWeight\n");

    int e = 0, i = 0, totalCost = 0;

    while (e < V - 1 && i < E) {

        struct Edge next_edge = edges[i++];

        int x = find(parent, next_edge.src);

        int y = find(parent, next_edge.dest);

        if (x != y) {

            printf("%d - %d \t%d\n", next_edge.src, next_edge.dest, next_edge.weight);

            totalCost += next_edge.weight;

            unionSets(parent, rank, x, y);

            e++;

        }

    }

    printf("Total Minimum Cost of Spanning Tree = %d\n", totalCost);

    free(parent);

    free(rank);

}

int main() {

    int V = 4;

    int E = 5;

    struct Edge edges[] = {

        {0, 1, 10},

        {0, 2, 6},

        {0, 3, 5},

        {1, 3, 15},

        {2, 3, 4}

    };

    kruskalMST(edges, V, E);

    return 0;

}
