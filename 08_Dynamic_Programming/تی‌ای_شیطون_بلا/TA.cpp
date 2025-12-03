#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, u, r;
    cin >> n >> u >> r;

    vector<int> a(n), b(n), k(n), p(n);

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> k[i];
    for (int i = 0; i < n; ++i) cin >> p[i];

    int max_sum = 0;

    for (int i = 0; i < (1 << u); ++i) {
        vector<int> temp_a = a;
        int current_sum = 0;
        
        for (int j = 0; j < n; ++j) {
            current_sum += temp_a[j] * k[j];
        }

        for (int j = 0; j < u; ++j) {
            if ((i >> j) & 1) {
                for (int x = 0; x < n; ++x) {
                    temp_a[x] = temp_a[x] ^ b[x];
                }
            } else {
                for (int x = 0; x < n; ++x) {
                    temp_a[x] = temp_a[p[x] - 1] + r;
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            current_sum += temp_a[j] * k[j];
        }

        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << endl;
    return 0;
}
