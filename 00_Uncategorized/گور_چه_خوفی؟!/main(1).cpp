#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, const vector<vector<int>>& adj, vector<int>& colors, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                colors[neighbor] = colors[node];
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> colors(n);  
    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;  
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    int operations = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int white_count = 0, black_count = 0;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            if (colors[i] == 0) white_count++;
            else black_count++;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                        if (colors[neighbor] == 0) white_count++;
                        else black_count++;
                    }
                }
            }

            operations += min(white_count, black_count);
        }
    }

    cout << operations << endl;

    return 0;
}
