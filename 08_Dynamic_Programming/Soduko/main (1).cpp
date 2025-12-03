#include <bits/stdc++.h>
using namespace std;

int Check(vector<vector<int>>& A, int n, int i, int j, int num) {
    int k = sqrt(n);
    for (int q = 0; q < n; q++) {
        if (A[q][j] == num)
            return 0;
    }
    for (int q = 0; q < n; q++) {
        if (A[i][q] == num)
            return 0;
    }
    int r = i - (i % k);
    int c = j - (j % k);
    for (int u = 0; u < k; u++) {
        for (int y = 0; y < k; y++) {
            if (A[r + u][c + y] == num)
                return 0;
        }
    }
    return 1;
}

bool solve(vector<vector<int>>& A, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == -1) {
                for (int q = 1; q <= n; q++) {
                    if (Check(A, n, i, j, q)) {
                        A[i][j] = q;
                        if (solve(A, n))
                            return true;
                        A[i][j] = -1;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> Soduko(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> Soduko[i][j];
    }
    if (solve(Soduko, n)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << Soduko[i][j] << " ";
            }
            cout << endl;
        }
    }
}
