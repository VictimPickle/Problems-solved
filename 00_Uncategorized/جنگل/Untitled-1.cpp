#include <bits/stdc++.h>
using namespace std;

void F(vector<vector<int>>& M, int x, int y, int r, int c) {
    if (x < 0 || y < 0 || x >= r || y >= c || M[x][y] == 0)
        return;
    M[x][y] = 0;
    F(M, x + 1, y, r, c);
    F(M, x - 1, y, r, c);
    F(M, x, y + 1, r, c);
    F(M, x, y - 1, r, c);
}

int G(vector<vector<int>> M, int r, int c) {
    int t = 0;
    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            if (M[x][y] == 1) {
                t++;
                F(M, x, y, r, c);
            }
        }
    }
    return t;
}

bool I(vector<vector<int>>& M, int r, int c) {
    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            if (M[x][y] == 1) {
                M[x][y] = 0;
                if (G(M, r, c) != 1) {
                    M[x][y] = 1;
                    return true;
                }
                M[x][y] = 1;
            }
        }
    }
    return false;
}

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> M(r, vector<int>(c));
    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            cin >> M[x][y];
        }
    }

    int t = G(M, r, c);

    if (t != 1) {
        cout << 0 << endl;
        return 0;
    }

    cout << (I(M, r, c) ? 1 : 2) << endl;

    return 0;
}
