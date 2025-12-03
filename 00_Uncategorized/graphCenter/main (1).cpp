#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int MAX_N = 100;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> d(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, val;
        cin >> u >> v >> val;
        u--; v--;
        d[u][v] = val;
        d[v][u] = val;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] != INF && d[k][j] != INF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    vector<int> e(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] != INF) {
                e[i] = max(e[i], d[i][j]);
            }
        }
    }
    int radius = INF;
    for (int i = 0; i < n; i++) {
        radius = min(radius, e[i]);
    }

    set<int> center;
    for (int i = 0; i < n; i++) {
        if (e[i] == radius) {
            center.insert(i + 1);
        }
    }

    cout << *center.begin() << endl;

    return 0;
}
