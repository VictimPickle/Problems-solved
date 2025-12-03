#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long int n;
    cin >> n;
    vector<long long int> A(n);
    long long int B[102] = {0};
    long long int x = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        long long int y = A[i];
        B[y]++;
        for(long long int j = y + 1 ; j< 102 ; j++) {
            if(B[j] > 0)
                x += B[j];
        }
    }
    cout<< x;

    // cout << Count(A);
    return 0;
}
