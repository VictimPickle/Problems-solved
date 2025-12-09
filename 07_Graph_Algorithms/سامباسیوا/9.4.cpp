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


vector<int> A[100005];
vector<int> Arev[100005];
bool visited[100005] = {false};
int n, m;


void dfs(int node, vector<int> graph[]) {
    visited[node] = true;
    for (int x : graph[node]) {
        if (!visited[x]) {
            dfs(x, graph);
        }
    }
}
int main(){IOS CT
    cin >>n >> m;
    FOR(m){int x ,y ; cin >> x >> y;    A[x].push_back(y); Arev[y].push_back(x);}
    dfs(1, A);
    for(int i = 1; i <= n; i++)  if(!visited[i]){cout<<"NO"<<endl; return 0;}
    for(int i = 1 ; i <= sizeof(visited) ; i++)   visited[i] = false;
    dfs(1, Arev);
    for(int i = 1; i <= n; i++)  if(!visited[i]){cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
    return 0;
}
