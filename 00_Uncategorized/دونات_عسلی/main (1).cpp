#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<int>> createGraph(int maxNode) {
    unordered_map<int, vector<int>> g;

    g[1] = {2, 3, 4, 5, 6};
    for (int n = 2; n <= 6; n++) {
        g[n].push_back(1);
        g[n].push_back(n == 6 ? 2 : n + 1);
        g[n].push_back(n == 2 ? 6 : n - 1);
        g[n].push_back(2*n+2);
        g[2*n+2].push_back(n);
        g[n].push_back(2*n+3);
        g[2*n+3].push_back(n);
        g[n].push_back(2*n+4);
        g[2*n+4].push_back(n);
    }

    int start = 7, next = 17;

    while (start <= maxNode) {
        for (int n = start; n < next && n <= maxNode; n++) {
            // if (g.find(n) == g.end()) g[n] = {};

            if (n > start) {
                g[n].push_back(n - 1);
                g[n - 1].push_back(n);
            }
            if (n < next - 1 && n < maxNode) {
                g[n].push_back(n + 1);
                g[n + 1].push_back(n);
            }

            int base = 2 * n + 2;
            if (base <= maxNode) {
                g[n].push_back(base);
                g[base].push_back(n);
            }
            if (base + 1 <= maxNode) {
                g[n].push_back(base + 1);
                g[base + 1].push_back(n);
            }
            if (base + 2 <= maxNode) {
                g[n].push_back(base + 2);
                g[base + 2].push_back(n);
            }
        }

        start = next;
        next = 2 * next + 3;
    }
    //
    // for (int i = 15; i <= maxNode; i = i * 2 + 3) {
    //     if (i + 1 <= maxNode) {
    //         g[i].push_back(i + 1);
    //         g[i + 1].push_back(i);
    //     }
    // }

    int step = 5;
    for (int i = 2; i <= maxNode;) {
        int k = 4 * i + 8;
        if (k <= maxNode) {
            g[k].push_back(i);
            g[i].push_back(k);
        }
        i += step;
        step *= 2;
    }

    return g;
}

int findShortestPath(const unordered_map<int, vector<int>> &g, int start, int end) {
    if (start == end) return 0;

    unordered_map<int, bool> vis;
    queue<pair<int, int>> q;

    q.push({start, 0});
    vis[start] = true;

    while (!q.empty()) {
        auto [cur, dist] = q.front();
        q.pop();

        // if (g.find(cur) == g.end()) continue;

        for (int nbr : g.at(cur)) {
            if (!vis[nbr]) {
                if (nbr == end) return dist + 1;
                q.push({nbr, dist + 1});
                vis[nbr] = true;
            }
        }
    }

    // return -1;
}

int main() {
    int start, end;
    cin >> start >> end;

    int maxNode = 1500000;
    unordered_map<int, vector<int>> graph = createGraph(maxNode);

    cout << findShortestPath(graph, start, end) << endl;

    return 0;
}
