#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , q;
    cin >> n >> q;
    
    vector<vector<int>>A(n+1, vector<int>(n+1,0));
    for(int i = 1 ; i<= n ; i++){
        for(int j = 1 ; j<= n ; j++){
            char x;
            cin >> x;
            if(x == '*')
                A[i][j] = 1;
        }
    }
    vector<vector<int>>B(n+1, vector<int>(n+1, 0));
    for(int i = 1 ; i<= n; i++){
        for(int j = 1 ; j<=n ; j++){
            B[i][j] = A[i][j] + B[i-1][j]+ B[i][j-1] - B[i-1][j-1];
        }
        
    }

    for(int k = 0 ; k<q ; k++){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<B[x2][y2] - B[x1-1][y2] - B[x2][y1-1] + B[x1-1][y1-1]<<"\n";
        
    }
    return 0;
}
// Searched for this type of question and found a solution named "Prefix sum"
// searchd GFG for it and found a solution : https://www.geeksforgeeks.org/dsa/sprefix-sum-2d-array/