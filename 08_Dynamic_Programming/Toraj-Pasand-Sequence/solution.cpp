#include<iostream>
#include<vector>

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

typedef vector<ll> VLL;

const ll MOD = 1e9 + 7;

typedef vector<vector<ll>> dp;

dp multiply(const dp& A, const dp& B) {

int n = A.size();

dp C(n, vector<ll>(n, 0));

for (int i = 0; i < n; i++) {

for (int k = 0; k < n; k++) {

if (A[i][k] == 0) continue;

for (int j = 0; j < n; j++) {

C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;

}

}

}

return C;

}

dp power(dp A, ll p) {

int n = A.size();

dp res(n, vector<ll>(n, 0));

for (int i = 0; i < n; i++) res[i][i] = 1;

while (p > 0) {

if (p & 1) res = multiply(res, A);

A = multiply(A, A);

p /= 2;

}

return res;

}

int main() {

IOS CT

ll k, d;

cin >> d >> k;

int n = 2 * d + 1;

dp T(n, vector<ll>(n, 0));

FOR(n) {

int r = i;

for (int c = 0; c < n; c++) {

if (abs(r - c) <= d) T[r][c] = 1;

}

}

if (k == 1) {

cout << n % MOD << endl;

return 0;

}

dp Res = power(T, k - 1);

ll ans = 0;

for (int i = 0; i < n; i++) {

for (int j = 0; j < n; j++) ans = (ans + Res[i][j]) % MOD;

}

cout << ans;

return 0;

}
