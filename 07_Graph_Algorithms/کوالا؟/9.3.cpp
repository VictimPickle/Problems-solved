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
typedef vector<long long> VLL;
VI e[100005];
bool visited[100005] = {false};
ll x[100005], y[100005];
void dfs(int a , VI &t){
    visited[a] = true;
    t.push_back(a);
    for(auto j : e[a]){
        if(!visited[j]) dfs(j, t);
    }
}
int main(){IOS CT
    int n , m;  cin >> n >> m;
    for(int i = 1 ; i <=n ; i++)    cin>>x[i]>>y[i];
    for(int i =0 ; i < m ; i++){
        int a , b;
        cin >> a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    ll minp = LLONG_MAX;
    for(int i =1 ; i <= n ; i++){
        if(!visited[i]){
            VI t; dfs(i,t);
            ll minx = LLONG_MAX;
            ll miny = LLONG_MAX;
            ll maxx = LLONG_MIN;
            ll maxy = LLONG_MIN;
            for(auto j : t){
                minx = min(minx , x[j]);
                miny = min(miny , y[j]);
                maxx = max(maxx , x[j]);
                maxy = max(maxy , y[j]);
            }
            ll p = 2 * ((maxx-minx)+ (maxy - miny));
            minp = min(minp , p);
        }
    }
    cout << minp<<endl;return 0;
}
