#include <bits/stdc++.h>
using namespace std;
bool enough(const vector<long long> x, int n, int m,int c, long long r) {
    long long used = 0;
    long long i = 0;
    while ( n > i){
        used ++;
        long long until = x[i] + r;
        long long a = 0;
        while( n > i && x[i] <= until && a < c)  i++, a++;
        if(used > m)    return false;
    }
    return true;
}

int main() {
    long long n , m, c;
    cin >> n >> m >> c;
    vector<long long> x(n);
    for (int i = 0; i < n; i++)     cin >> x[i];
    sort(x.begin(), x.end());

    long long low = 0;
    long long high = 1e18;

    while (low < high) {
        long long mid = (low + high) / 2;
        if (enough( x,n , m ,c ,mid))
            high = mid;    
        else
            low = mid + 1;
    }
    cout << low << endl;
    return 0;
}
