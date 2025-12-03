#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>> &revg, vector<set<int>> &B, vector<bool> &visited) {
    visited[node] = true;
    for (int neighbor : revg[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, revg, B, visited);
        }
        B[node].insert(B[neighbor].begin(), B[neighbor].end());
        B[node].insert(neighbor);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> revg(n);
    vector<set<int>> B(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        revg[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            DFS(i, revg, B, visited);
    }

    for (int i = 0; i < n; i++) {
        for (int x : B[i])
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
