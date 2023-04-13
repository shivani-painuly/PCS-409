#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 100; // maximum number of vertices

vector<int> adj[MAX]; // adjacency list to represent the graph
int color[MAX]; // to keep track of color of each vertex

bool bfs(int src, int n) {
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : adj[u]) {
            if(color[v] == 0) {
                color[v] = 3 - color[u]; // assign opposite color to v
                q.push(v);
            } else if(color[v] == color[u]) {
                return false; // same color adjacent vertices => not bipartite
            }
        }
    }
    return true;
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
    color[MAX] = {0};
    for(int i=0; i<n; i++) {
        if(color[i] == 0) {
            if(!bfs(i, n)) {
                cout << "Not Bipartite";
                return 0;
            }
        }
    }
    cout << "Yes Bipartite";
    return 0;
}
