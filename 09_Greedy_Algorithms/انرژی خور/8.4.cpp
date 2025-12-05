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
    ll n , k ; cin>> n >> k;
    vector<PLL> A(n);
    FOR(n)  cin >> A[i].first >> A[i].second;
    Sort(A);
    FOR(n){
        if(A[i].first > k)  continue;
        if(A[i].second > A[i].first)
            k += A[i].second- A[i].first;

    }
    cout<< k<< endl;
    return 0;
}