#include<bits/stdc++.h>

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

typedef pair<ll,ll> PLL;

typedef pair<int,int> PII;

typedef vector<int> VI;

typedef vector<ll> VLL;

const ll Maxn = 100005;

int parent[Maxn];

struct edge{

int a; int b; int cost;

};

int find(int x){

return parent[x]== x ? x : parent[x] = find(parent[x]);

}

bool unite(int x, int y){

x = find(x) ; y = find(y);

if (x==y) return false;

parent[y] = x;

return true;

}

bool comp(edge a , edge b){

return a.cost < b.cost;

}

int main(){

int n , m ;

cin >> n >> m;

vector<edge> Graph(m);

for(int i = 0 ; i< m ; i++) cin >> Graph[i].a >> Graph[i].b >> Graph[i].cost; sort(Graph.begin() , Graph.end() , comp);

for(int i = 1 ; i <= n ; i++) parent[i] = i;

ll cost = 0, edges = 0;

for(int i = 0 ; i < m ; i++){

int a= Graph[i].a , b = Graph[i].b , c = Graph[i].cost;

if(unite(a,b)) {

cost += c;

edges++;

if(edges == n-1)break;

}

}

if(edges == n-1) cout << cost << endl;

else cout << "IMPOSSIBLE" << endl;

return 0;

}