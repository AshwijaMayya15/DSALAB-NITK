#include <ios#include <iostream>
#include <stack>
#define MAX 100
using namespace std;

int adj[MAX][MAX];   // Adjacency matrix
bool visited[MAX];   // Visited array

void dfs_iterative(int start, int n) {
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (!visited[u]) {
            cout << u << " ";
            visited[u] = true;

            // Push neighbors in reverse order to maintain consistent DFS
            for (int v = n - 1; v >= 0; v--) {
                if (adj[u][v] == 1 && !visited[v]) {
                    st.push(v);
                }
            }
        }
    }
}

int main() {
    int n, e, u, v;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    // Initialize adjacency matrix and visited
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u][v] = 1; // Directed graph
    }

    cout << "\nDFS Traversal (Iterative, Full Graph): ";
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs_iterative(i, n);
    }

    return 0;
}