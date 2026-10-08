#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MAX = 5;

vector<vector<int>> graph1 = {
    {0, 2, 0, 0, 9, 8, 0, 0, 0, 0, 0, 0},
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
    {0, 0, 0, 0, 0, 0, 0,15,20, 0,17, 0}
};

vector<vector<int>> graph = {
    {0, 4, 8, 0, 0},
    {4, 0, 3, 0, 0},
    {8, 3, 0, 6, 0},
    {0, 0, 0, 0,10},
    {0, 6, 0,10, 0}
};


void dijkstra(int start)
{
    vector<int> dist(MAX, INT_MAX);
    vector<bool> visited(MAX, false);

    dist[start] = 0;

    for (int count = 0; count < MAX; count++)
    {
        // Find unvisited vertex with minimum distance
        int current = -1;

        for (int i = 0; i < MAX; i++)
        {
            if (!visited[i] &&
                (current == -1 || dist[i] < dist[current]))
            {
                current = i;
            }
        }

        // No more reachable vertices
        if (current == -1 || dist[current] == INT_MAX)
            break;

        visited[current] = true;

        // Relax adjacent vertices
        for (int i = 0; i < MAX; i++)
        {
            if (graph[current][i] != 0 &&
                !visited[i] &&
                dist[current] + graph[current][i] < dist[i])
            {
                dist[i] = dist[current] + graph[current][i];
            }
        }

        // Print table
        cout << "\nDistance: ";
        for (int i = 0; i < MAX; i++)
        {
            if (dist[i] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i] << " ";
        }

        cout << "\nVisited:  ";
        for (int i = 0; i < MAX; i++)
        {
            cout << visited[i] << " ";
        }
        cout << "\n";
    }

    cout << "\nFinal shortest distances:\n";

    for (int i = 0; i < MAX; i++)
    {
        cout << "Vertex " << i + 1 << " : ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << "\n";
    }
}

int main()
{
    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    dijkstra(start - 1);

    return 0;
}