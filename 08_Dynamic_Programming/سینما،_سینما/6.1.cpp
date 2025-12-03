#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9;
int main() {
    int n, b;
    cin >> n >> b;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<ll>> dp0(n + 1, vector<ll>(b + 1, INF));
    vector<vector<ll>> dp1(n + 1, vector<ll>(b + 1, INF));
    dp0[1][1] = 0;
    dp1[1][0] = 0;
    for (int i = 2; i <= n; i++) {
        for (int k = 0; k <= b; k++) {
            if (i - k < 0 || i - k > b) continue;

            if (k >= 1) {
                ll v0 = dp0[i - 1][k - 1];
                ll v1 = dp1[i - 1][k - 1] + a[i];
                dp0[i][k] = min(dp0[i][k], min(v0, v1));
            }
            if (k <= i - 1) {
                ll v1 = dp1[i - 1][k];
                ll v0 = dp0[i - 1][k] + a[i];
                dp1[i][k] = min(dp1[i][k], min(v1, v0));
            }
        }
    }

    ll ans = INF;
    for (int k = 0; k <= b; k++) {
        ans = min(ans, dp0[n][k]);
        ans = min(ans, dp1[n][k]);
    }

    cout << ans << '\n';
    return 0;
}
