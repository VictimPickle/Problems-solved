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
const int MAXW = 1000005;

struct Item {
    ll w, v;
    long double r;
};

int n;
ll W;
vector<Item> a;
ll bestAns = 0;

long long greedybound(int idx, ll cap) {
    if (cap <= 0 || idx >= n) return 0;
    long double res = 0;
    ll rem = cap;
    for (int i = idx; i < n && rem > 0; i++) {
        if (a[i].w <= rem) {
            rem -= a[i].w;
            res += a[i].v;
        } else {
            res += (long double)rem * a[i].v / a[i].w;
            break;
        }
    }
    return (long long)res;
}

void bb(int idx, ll curW, ll curV) {
    if (idx == n) {
        if (curV > bestAns) bestAns = curV;
        return;
    }
    ll ub = curV + greedybound(idx, W - curW);
    if (ub <= bestAns) return;
    
    if (curW + a[idx].w <= W) {
        bb(idx + 1, curW + a[idx].w, curV + a[idx].v);
    }
    bb(idx + 1, curW, curV);
}

int main() {
    IOS; CT;
    cin >> n >> W;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].w >> a[i].v;
        a[i].r = (long double)a[i].v / a[i].w;
    }
    sort(a.begin(), a.end(), [](Item& x, Item& y) { return x.r > y.r; });
    bb(0, 0, 0);
    cout << bestAns;
    return 0;
}
