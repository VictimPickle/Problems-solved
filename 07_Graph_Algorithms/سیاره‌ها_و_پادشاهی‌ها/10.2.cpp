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

int n, m, idx, cnt;

VI adj[100005];

VI A, lowlink, scc;

vector<bool> onStack;

stack<int> st;

void dfs(int v) {
	A[v] = lowlink[v] = idx++;
	st.push(v);
	onStack[v] = true;

	for (int w : adj[v]) {
		if (A[w] == -1) {
			dfs(w);
			lowlink[v] = min(lowlink[v], lowlink[w]);
		} elif (onStack[w]) lowlink[v] = min(lowlink[v], A[w]);
	}

	if (lowlink[v] == A[v]) {
		while (true) {
			int w = st.top(); st.pop();
			onStack[w] = false;
			scc[w] = cnt;
			if (w == v) break;
		}
		cnt++;
	}
}

int main() {
	IOS CT
	cin >> n >> m;

	A.assign(n, -1);
	lowlink.assign(n, 0);
	scc.assign(n, 0);
	onStack.assign(n, false);
	idx = 0;
	cnt = 1;

	FOR(m) {
		int a, b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
	}

	FOR(n) {
		if (A[i] == -1) dfs(i);
	}

	FOR(n) scc[i] = cnt - scc[i];

	cout << cnt-1 << endl;
	FOR(n) {
		cout << scc[i];
		if (i < n-1) cout << " ";
	}

	return 0;
}
