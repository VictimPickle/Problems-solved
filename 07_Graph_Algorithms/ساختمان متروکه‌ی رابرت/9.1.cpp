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

int n, m;
char A[1005][1005];
bool visited[1005][1005];
bool isAccessible(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && !visited[i][j] && A[i][j] == '.';
}

void bfs(int i, int j) {
    if (!isAccessible(i, j)) return;
    
    queue<PII> q;
    q.push({i, j});
    visited[i][j] = true;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    while (!q.empty()) {
        auto[x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (isAccessible(nx, ny)) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    IOS CT
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
            visited[i][j] = false;
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i][j] == '.' && !visited[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    
    cout << cnt << '\n';
    return 0;
}