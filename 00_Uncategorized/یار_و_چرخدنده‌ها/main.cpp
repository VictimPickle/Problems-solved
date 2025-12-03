#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class UnionFind {
public:
    vector<int> parent, size, rotation;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        rotation.resize(n, -1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            int root = find(parent[x]);
            rotation[x] ^= rotation[parent[x]];
            parent[x] = root;
        }
        return parent[x];
    }

    void unite(int x, int y, int rel) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            rotation[rootY] = rel ^ rotation[x] ^ rotation[y];
        }
    }

    int getRotation(int x) {
        find(x);
        return rotation[x];
    }
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    UnionFind uf(n);
    while (m--) {
        int v, u;
        cin >> v >> u;
        v--; u--; 

        uf.unite(v, u, 1); 
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--; 

        if (uf.find(a) != uf.find(b)) {
            cout << "impossible" << endl;
        } else {
            int rel = uf.getRotation(a) ^ uf.getRotation(b);
            if (rel == 0) {
                cout << "independent" << endl;
            } else if (rel == 1) {
                cout << "ccw" << endl;
            } else {
                cout << "cw" << endl;
            }
        }
    }

    return 0;
}
