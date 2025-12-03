    #include <bits/stdc++.h>
    using namespace std;

bool enough(const vector<long long> A, long long mid, int n, long long k) {
    long long sum = 0;
    for (int i =0 ; i < n ; i++) {
        long long x= A[i];
        sum += mid / x;
        if (sum >= k) return true;
    }
    return false;
}

int main() {
    int n; 
    long long k;
    cin >> n >> k;
    vector<long long> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    long long start = 0, end = (long long)1e18; 
    while (start < end) {
        long long mid = (start + end)/ 2;
        if (enough(A, mid,n, k)) end = mid;
        else start = mid + 1;
    }
    cout << start << "\n";
    return 0;
}
