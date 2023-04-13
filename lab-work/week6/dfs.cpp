#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100; // maximum number of vertices

int adj[MAX][MAX]; // adjacency matrix to represent the graph

bool dfs(int u, int v, bool visited[], int n) {
    visited[u] = true;
    if(u == v) {
        return true;
    }
    for(int i=0; i<n; i++) {
        if(adj[u][i] == 1 && !visited[i]) {
            if(dfs(i, v, visited, n)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int n; // number of vertices in the graph
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> adj[i][j];
        }
    }
    int u, v; // source and destination vertices
    cin >> u >> v;
    bool visited[MAX] = {false}; // initialize visited array to false
    if(dfs(u, v, visited, n)) {
        cout << "Yes Path Exists";
    } else {
        cout << "No Such Path Exists";
    }
    return 0;
}
