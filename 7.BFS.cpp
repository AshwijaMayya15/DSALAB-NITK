#include <iostream>
#include <queue>
#define MAX 100

using namespace std;

int adj[MAX][MAX];
int color[MAX];  // 0: White, 1: Gray, -1: Black
int d[MAX];      // Distance from source
int pi[MAX];     // Parent array

void bfs(int n, int s) {
    queue<int> q;
   
    for (int i = 0; i < n; i++) {
        color[i] = 0;  // White (unvisited)
        d[i] = -1;     // Undefined distance
        pi[i] = -1;    // No parent
    }
   
    color[s] = 1;  // Gray (discovered)
    d[s] = 0;
    q.push(s);
   
    while (!q.empty()) {  
        int u = q.front();  
        q.pop();
       
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && color[v] == 0) {  
                color[v] = 1;  
                d[v] = d[u] + 1;
                pi[v] = u;
                q.push(v);
            }
        }
        color[u] = -1;
    }
}

void printShortestPath(int s, int v) {
    if (v == s) {
        cout << s << " ";
    } else if (pi[v] == -1) {
        cout << "No path from " << s << " to " << v << " exists.\n";
    } else {
        printShortestPath(s, pi[v]);
        cout << v << " ";
    }
}

int main() {
    int n, e, u, v, s;
   
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;
   
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
   
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
   
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
   
    cout << "Enter source vertex: ";
    cin >> s;
   
    bfs(n, s);
   
    cout << "Vertex distances from source " << s << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ": Distance = " << d[i] << "\n";
    }

    cout << "Enter destination vertex for shortest path: ";
    cin >> v;
    cout << "Shortest path from " << s << " to " << v << ": ";
    printShortestPath(s, v);
    cout << endl;
   
    return 0;
}