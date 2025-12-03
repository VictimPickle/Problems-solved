#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> mem(n, 1);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int q = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j] && mem[j] + 1 > mem[i]) {
                mem[i] = mem[j] + 1;
            }
        }
        q = max(q, mem[i]);
    }

    cout << q;
}
