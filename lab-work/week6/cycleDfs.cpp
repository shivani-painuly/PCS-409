#include<iostream>
#include<vector>
using namespace std;

const int MAX = 100; // maximum number of vertices

vector<int> adj[MAX]; // adjacency list to represent the graph
bool visited[MAX]; // to keep track of visited vertices during DFS
bool recursionStack[MAX]; // to keep track of vertices in current recursion stack

bool dfs(int u) {
    visited[u] = true;
    recursionStack[u] = true;

    for(auto v : adj[u]) {
        if(!visited[v]) {
            if(dfs(v)) {
                return true;
            }
        } else if(recursionStack[v]) {
            return true;
        }
    }
    recursionStack[u] = false;
    return false;
}

int main() {
    int n; // number of vertices in the graph
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int x;
            cin >> x;
            if(x == 1) {
                adj[i].push_back(j);
            }
        }
    }
    visited[MAX] = {false};
    recursionStack[MAX] = {false};

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            if(dfs(i)) {
                cout << "Yes Cycle Exists";
                return 0;
            }
        }
    }
    cout << "No Cycle Exists";
    return 0;
}
