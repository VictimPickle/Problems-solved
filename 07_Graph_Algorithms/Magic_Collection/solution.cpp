#include <bits/stdc++.h>

using namespace std;

#define WTF cout<< "WTF" << '\n';
#define END exit(0);
#define elif else if
#define IOS ios::sync_with_stdio(0);
#define CT cin.tie(0);
#define CinArr(arr, n); for(int i = 0; i < n; i++) cin >> arr[i];
#define CinArrK(arr, n , k); for(int i = k; i < n; i++) cin >> arr[i];
#define Sort(a) sort(a.begin(), a.end());
#define FOR(a) for(int i = 0 ; i < a ; i++)

typedef long long ll;
typedef pair<ll, ll> PLL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<ll> VLL;

const int N = 100000 + 5;

int n, m;
ll c[N];
vector<int> g[N], gr[N];
bool visited[N];
vector<int> order;
int comp[N];
ll sum[N];
int cnt = 0;
vector<int> dag[N];
ll dp[N];

void dfs1(int v) {
    visited[v] = true;
    for (int t : g[v])
        if (!visited[t]) dfs1(t);
    order.push_back(v);
}

void dfs2(int v, int c_id) {
    comp[v] = c_id;
    sum[c_id] += c[v];
    for (int t : gr[v])
        if (comp[t] == -1) dfs2(t, c_id);
}

ll dfs_dp(int v) {
    if (dp[v] != -1) return dp[v];
    ll best = 0;
    for (int t : dag[v]) {
        best = max(best, dfs_dp(t));
    }
    return dp[v] = sum[v] + best;
}

int main() {
    IOS CT
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    
    for (int i = 1; i <= n; ++i)
        if (!visited[i]) dfs1(i);
    
    for (int i = 0; i <= n; ++i) comp[i] = -1;
    for (int i = order.size() - 1; i >= 0; i--) {
        int v = order[i];
        if (comp[v] == -1) {
            cnt++;
            dfs2(v, cnt);
        }
    }
    
    for (int u = 1; u <= n; ++u) {
        for (int v : g[u]) {
            int cu = comp[u];
            int cv = comp[v];
            if (cu != cv) dag[cu].push_back(cv);
        }
    }
    
    for (int i = 0; i <= cnt; ++i) dp[i] = -1;
    ll ans = 0;
    for (int i = 1; i <= cnt; ++i)
        ans = max(ans, dfs_dp(i));
    cout << ans;
    return 0;
}
