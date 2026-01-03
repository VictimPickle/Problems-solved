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
VI ans;
vector<bool> mark;

bool backtrack(int x) {
    if (x == n) return 1;
    for (int i = x + 1; i < n; i++) {
        if (!mark[i] && (ans.empty() || abs(ans.back() - i) == 1)) {
            ans.push_back(i);
            mark[i] = 1;
            if (i == x + 1) {
                // If we placed x+1, find next unplaced and try from there
                int tmp = x + 1;
                while (mark[tmp]) tmp++;
                if (backtrack(tmp - 1)) return 1;
            } else {
                // If we placed something > x+1, try next position
                if (backtrack(x)) return 1;
            }
            ans.pop_back();
            mark[i] = 0;
        }
    }
    return 0;
}

int main() {
    IOS; CT;
    cin >> n;
    mark.assign(n + 1, 0);
    if (backtrack(0)) {
        for (int i : ans) cout << i << " ";
        cout << "\n";
    } else {
        cout << "NO SOLUTION";
    }
    return 0;
}
