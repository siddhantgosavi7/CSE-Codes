#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int V; // Number of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
        //arr = new int[v]
    }

    void addEdge(int u, int v) {
        adj[v].push_back(u); // Add u to v’s list.
        adj[u].push_back(v); // Add v to u’s list.
    }

    void printAdjList() {
        for(int i = 0; i < V; i++) {
            cout << i << ": ";
            for (auto x : adj[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    void bfs() {
        cout << "BFS: ";

        queue<int> Q;
        vector<bool> vis(V, false);

        Q.push(0);
        vis[0] = true;

        while(Q.size() > 0) {
            int u = Q.front();
            Q.pop();

            cout << u << " ";

            for(int x : adj[u]) {
                if(!vis[x]) {
                    vis[x] = true;

                    Q.push(x);
                }
            }
        }

        cout << endl;
    }

    void dfsHelper(int u, vector<bool> &vis) {
        cout << u << " ";
        vis[u] = true;
        
        for(int x : adj[u]) {
            if(!vis[x]) {
                dfsHelper(x, vis);
            }
        }
    }

    void dfs() {
        cout << "DFS: ";
        int src = 0;
        vector<bool> vis(V, false);

        dfsHelper(src, vis);

        cout << endl;
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    //g.printAdjList(); // Print the adjacency list representation of the graph

    //g.bfs();

    g.dfs();

    return 0;
}