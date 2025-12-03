#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> A(n);
    for(int i = 0; i < n ; i++)  cin>>A[i];
    vector<vector<ll>> dp(n , vector<ll>(n , 0));
    for(int i = 0 ; i < n ; i++)    dp[i][i] = A[i];
    for(int l = 2 ; l<= n ; l++){
        for(int i = 0 ; i < n - l + 1 ; i++){
            int j = l + i -1;
            if( l == 2) dp[i][j] = max(A[i], A[j]);
            else   { 
                ll x = dp[i+2][j] ; ll y = dp[i + 1][j-1]; ll z = dp[i][j-2]; 
                ll left = A[i] + min(x,y);
                ll right = A[j] + min (y ,z);
                dp[i][j] = max(left , right);
            }

        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}