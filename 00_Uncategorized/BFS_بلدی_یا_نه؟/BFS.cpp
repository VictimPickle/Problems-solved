#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBFSValid(int n, vector<vector<int>>& adj, vector<int>& expectedOrder) {
    vector<int> bfsOrder(n);
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;

    int idx = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfsOrder[idx++] = node + 1;
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    return bfsOrder == expectedOrder;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> adj(n);
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> expectedOrder(n);
    for (int i = 0; i < n; ++i) {
        cin >> expectedOrder[i];
    }

    if (isBFSValid(n, adj, expectedOrder)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
