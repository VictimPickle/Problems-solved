#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , m;  cin >> n >>m;
    vector<int> A(n), B(m);
    for(int i =0 ; i < n ; i++)     cin>>A[i];
    for(int i = 0 ; i < m ; i++)    cin>>B[i];
    // I will use a DP that i shows first i elemnts of A , j shows first j elemnts of B;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1 , 0));
    dp[0][0] = 0;
    for(int i = 1 ; i  <= n  ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(A[i-1] == B[j-1])    dp[i][j] = dp[i-1][j-1] +1;
            else    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]); 
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}