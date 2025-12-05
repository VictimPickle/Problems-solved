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
    int n, m, k;  cin >> n >> m >> k;
    VI A(n), B(m);
    CinArr(A,n) CinArr(B,m)
    Sort(A) Sort(B)
    int cnt = 0;
    int i = 0, j = 0;
    while(i < n && j < m){
        if(abs(A[i] - B[j]) <= k){
            cnt++;
            i++;
            j++;
        } elif(A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    }
    cout << cnt << endl;
    return 0;
}