#include <iostream>
#include <cmath>
using namespace std;

char pattern[3][3];
char ans[1000][1000];

void Solve(int n, int k, int x, int y) {
    if (k == 0)
        return;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pattern[i][j] == '*' || pattern[i][j] == '//') {
                int startx = x + i * pow(n, k - 1);
                int finishx = x + (i + 1) * pow(n, k - 1);
                for (int e = startx; e < finishx; e++) {
                    int starty = y + j * pow(n, k - 1);
                    int finishy = y + (j + 1) * pow(n, k - 1);
                    for (int w = starty; w < finishy; w++) {
                        ans[e][w] = pattern[i][j];
                    }
                }
            } else {
                Solve(n, k - 1, x + i * pow(n, k - 1), y + j * pow(n, k - 1));
            }
        }
    }
}

int main() {
    int k, n;
    cin >> n >> k;
    for (int i = 0; i < pow(n, k); i++) {
        for (int j = 0; j < pow(n, k); j++) {
            ans[i][j] = '.';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> pattern[i][j];
        }
    }
    Solve(n, k, 0, 0);
    int size = pow(n, k);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
