#include <bits/stdc++.h>
using namespace std;
bool enough(const vector<long long> x, int n, int k, long long r) {
    long long used = 0;
    long long i = 0;
    while ( n > i){
        used ++;
        long long until = x[i] + 2*r;
        while( n > i && x[i] <= until)  i++;
        if(used > k)    return false;
    }
    return true;
}

int main() {
    long long n , k;
    cin >> n >> k;
    vector<long long> x(n);
    for (int i = 0; i < n; i++)     cin >> x[i];
    sort(x.begin(), x.end());

    long long low = 0;
    long long high = 1e18;

    while (low < high) {
        long long mid = (low + high) / 2;
        if (enough( x,n , k,mid))
            high = mid;    
        else
            low = mid + 1;
    }
    cout << low << endl;
    return 0;
}
