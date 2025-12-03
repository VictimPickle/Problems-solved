#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int p, const vector<vector<int>>& g, vector<int>& par, vector<bool>& vis, set<vector<int>>& cycles) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) {
            par[v] = u;
            dfs(v, u, g, par, vis, cycles);
        } else if (v != p && par[u] != v) {
            vector<int> cycle;
            int cur = u;
            while (cur != v && cur != -1) {
                cycle.push_back(cur);
                cur = par[cur];
            }
            cycle.push_back(v);
            if (cur == v) {
                cycle.push_back(u);
                sort(cycle.begin(), cycle.end());
                cycles.insert(cycle);
            }
        }
    }
}

vector<vector<int>> findCycles(const vector<vector<int>>& g, int n) {
    vector<int> par(n + 1, -1);
    vector<bool> vis(n + 1, false);
    set<vector<int>> cycles;

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(i, -1, g, par, vis, cycles);
    }

    return vector<vector<int>>(cycles.begin(), cycles.end());
}

vector<int> shortestPath(const vector<vector<int>>& g, int start, const unordered_set<int>& cycleNodes) {
    queue<pair<int, vector<int>>> q;
    q.push({start, {start}});
    unordered_set<int> vis;
    vis.insert(start);

    while (!q.empty()) {
        int u = q.front().first;
        vector<int> path = q.front().second;
        q.pop();

        if (cycleNodes.count(u)) return path;

        for (int v : g[u]) {
            if (!vis.count(v)) {
                vis.insert(v);
                vector<int> newPath = path;
                newPath.push_back(v);
                q.push({v, newPath});
            }
        }
    }

    return {};
}

int main() {
    int k, n, m;
    cin >> k >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto cycles = findCycles(g, n);
    unordered_set<int> cycleNodes;
    for (const auto& cycle : cycles) {
        for (int u : cycle) cycleNodes.insert(u);
    }

    auto path = shortestPath(g, k, cycleNodes);

    if (!path.empty()) {
        for (int u : path) cout << u << " ";
        cout << endl;
    } else {
        cout << "No path to a cycle found" << endl;
    }

    return 0;
}
