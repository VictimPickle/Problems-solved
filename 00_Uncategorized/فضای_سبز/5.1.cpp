#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9 + 7;
int main(){
    ll n; 
    cin >> n;
    vector<vector<char>> A;
    for(int i = 0 ; i < n ; i++){
        vector<char> B;
        for(int j = 0 ; j < n ;  j++){
            char x;
            cin >> x;
            B.push_back(x);
        }
        A.push_back(B);
    }
    vector<vector<ll>> dp(n, vector<ll>(n , 0));
    if (A[0][0] == '*' || A[n-1][n-1] == '*'){cout << 0 << endl; return 0;}
    dp[0][0] = 1;
    for(int i = 0 ; i < n ; i++){
        for( int j = 0 ; j < n ; j++){
            if(A[i][j] == '*')
                dp[i][j] = 0;
        }
    }
    for(int i = 1 ; i < n ; i++){
        if(A[0][i] == '*')break;
        dp[0][i] = dp[0][i-1];
    }

    for(int i = 1 ; i < n ; i++){
        if(A[i][0] == '*')break;
        dp[i][0] = dp[i-1][0];
    }
    for(int i = 1 ; i < n ; i++){
        for( int j = 1 ; j < n ; j++){
            if(A[i][j] != '*')
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
        }
    }
    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < n ; j++)
    //         cout << dp[i][j]<<" ";
    //     cout<<endl;
    // }
    cout << dp[n-1][n-1]<<endl;
    return 0 ;
}
