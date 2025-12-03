#pragma GCC optimize("O3,unroll-loops") 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

ll MOD = 1e9 + 7;
// int count(int money , vector<ll> A , vector<ll> DP){
//     if (money == 0 || money <= min_element(A.begin() , A.end()))
//         return 1;
// }
int n ,x;
const int MAXN = 1000000 + 2;
ll dp[MAXN], A[MAXN];
ll coin;
int main(){
    IOS;
    cin >> n >> x;
    dp[0] = 1;
    // cout << dp[0] << endl;
    for(int i =0 ; i < n ; i++)cin >> A[i];
    for (int j = 0; j < n; ++j) {
    long long coin = A[j];
    if (coin > x) continue;
    for (int i = (int)coin; i <= x; ++i) {
        long long v = dp[i] + dp[i - coin];
        if (v >= MOD) v -= MOD;
        dp[i] = v;
    }
}

    cout << dp[x]<<endl;
}