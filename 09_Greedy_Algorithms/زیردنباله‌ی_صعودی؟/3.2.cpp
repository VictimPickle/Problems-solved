#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int n;
vector<int> A, dp;

bool cmp(int x, int y) {
    return A[x] < A[y];
}

void solve(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    solve(l, mid);

    vector<int> L, R;
    for (int i = l; i <= mid; ++i) L.push_back(i);
    for (int i = mid + 1; i <= r; ++i) R.push_back(i);

    sort(L.begin(), L.end(), cmp);
    sort(R.begin(), R.end(), cmp);

    long long acc = 0;
    int p = 0;
    for (int j : R) {
        while (p < (int)L.size() && A[L[p]] < A[j]) {
            acc += dp[L[p]];
            acc %= MOD;
            ++p;
        }
        dp[j] += acc;
        dp[j] %= MOD;
    }

    solve(mid + 1, r);
}

int main() {
    cin >> n;

    A = vector<int>(n + 1, 0);
    dp = vector<int>(n + 1, 1);

    for (int i = 1; i <= n; ++i)
        cin >> A[i];

    solve(1, n);

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dp[i];
        ans %= MOD;
    }

    cout << ans;
    return 0;
}

// https://robert1003.github.io/2020/01/31/cdq-divide-and-conquer.html
// حل تمرین زیردنباله صعودی توسط آقای مزینانی
