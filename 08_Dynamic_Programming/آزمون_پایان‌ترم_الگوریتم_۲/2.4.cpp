#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n , k;
    cin >> n >> k;
    vector<long long int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    map<long long int, long long int> B; 
    long long int res = 0, curr = 0;
    for (int i = 0; i < n; i++){
        curr += A[i];
        if (curr == k)
            res++;
        if (B.find(curr - k) != B.end())
            res += B[curr - k];
        B[curr]++;
    }
    cout << res << endl;
    //was Looking for methods of finding subarrays with sum and found "Subarray with Given Sum"(https://www.geeksforgeeks.org/dsa/find-subarray-with-given-sum-in-array-of-integers/)
    // Got the idea from this type of question(It just gives the first subarray found, I extended it for myself)
}
