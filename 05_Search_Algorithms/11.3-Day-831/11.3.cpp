#include <bits/stdc++.h>
using namespace std;
#define WTF cout << "WTF"
#define END exit(0)
#define elif else if
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0)
#define CinArr(arr, n) for(int i = 0; i < n; i++) cin >> arr[i]
#define CinArrK(arr, n , k) for(int i = k; i < n; i++) cin >> arr[i]
#define Sort(a) sort(a.begin(), a.end())
#define FOR(a) for(int i = 0; i < a; i++)
typedef long long ll;
typedef pair<ll, ll> PLL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<long long> VLL;

int n;
vector<bool> mark;
VI ans;

bool solve(int x) {
    if (x == n) return 1;
    for (int i = x + 1; i < n; i++) {
        if (!mark[i] && (ans.empty() || abs(ans.back() - i) == 1)) {
            ans.push_back(i);
            mark[i] = 1;
            if (i == x + 1) {
                int tmp = x + 1;
                while (tmp < n && mark[tmp]) tmp++;
                if (tmp == n) {
                    if (solve(tmp - 1)) return 1;
                } elif (solve(n)) return 1;
            } else if (solve(x)) return 1;
            ans.pop_back();
            mark[i] = 0;
        }
    }
    return 0;
}

void solve() {}

int main() {
    IOS; CT;
    cin >> n;
    mark.assign(n + 1, 0);
    if (solve(0)) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if (i < ans.size() - 1) cout << " ";
        }
    } else {
        cout << "NO SOLUTION" << endl;
    }
    return 0;
}
