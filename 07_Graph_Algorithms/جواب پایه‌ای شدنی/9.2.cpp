#include <bits/stdc++.h>
using namespace std;
#define WTF cout<< "WTF" << '\n';
#define END exit(0);
#define elif else if
#define IOS ios::sync_with_stdio(0);
#define CT cin.tie(0);
#define CinArr(arr, n); for(int i = 0; i < n; i++) cin >> arr[i];
#define CinArrK(arr, n , k); for(int i = k; i < n; i++) cin >> arr[i];
#define I i++
#define J j++
#define LINE cout << '\n'; 
#define Sort(a) sort(a.begin(), a.end());
#define FOR(a) for(int i = 0 ; i < a ; i++)
typedef long long ll;
typedef pair<ll, ll> PLL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<long long> VLL;

int main(){
    IOS CT
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> A(n+1);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        A[x].push_back(y);
        A[y].push_back(x);
    }
    vector<int> B(n+1, -1);
    queue<int> q;
    B[1] = 1;
    q.push(1);
    
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int v : A[x]){
            if(B[v] == -1){
                B[v] = B[x] + 1;
                q.push(v);
            }
        }
    }
    
    if(B[n] == -1) cout << "IMPOSSIBLE";
    else cout << B[n];
    
    return 0;
}