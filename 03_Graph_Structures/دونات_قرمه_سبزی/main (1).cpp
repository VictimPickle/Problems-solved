#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph, revGraph;
vector<int> order, sccId;
vector<bool> visited;
int sccCount;

void dfs1(int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) dfs1(neighbor);
    }
    order.push_back(node);
}

void dfs2(int node) {
    visited[node] = true;
    sccId[node] = sccCount;
    for (int neighbor : revGraph[node]) {
        if (!visited[neighbor]) dfs2(neighbor);
    }
}

int main() {
    int n;
    cin >> n;

    graph.resize(n + 1);
    revGraph.resize(n + 1);
    sccId.resize(n + 1, -1);

    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int neighbor;
            cin >> neighbor;
            graph[i].push_back(neighbor);
            revGraph[neighbor].push_back(i);
        }
    }

    visited.assign(n + 1, false);
    order.clear();
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) dfs1(i);
    }

    reverse(order.begin(), order.end());
    visited.assign(n + 1, false);
    sccCount = 0;

    for (int node : order) {
        if (!visited[node]) {
            dfs2(node);
            ++sccCount;
        }
    }

    vector<int> inDegree(sccCount, 0);
    vector<set<int>> hmm(sccCount);

    for (int u = 1; u <= n; ++u) {
        for (int v : graph[u]) {
            if (sccId[u] != sccId[v] && !hmm[sccId[u]].count(sccId[v])) {
                hmm[sccId[u]].insert(sccId[v]);
                ++inDegree[sccId[v]];
            }
        }
    }

    int result = 0;
    for (int i = 0; i < sccCount; ++i) {
        if (inDegree[i] == 0) ++result;
    }

    cout << result << endl;
    return 0;
}
