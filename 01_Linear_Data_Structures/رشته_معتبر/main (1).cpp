#include<bits/stdc++.h>
using namespace std;
int main() {
    string A;
    int n;
    cin>>n;
    cin >> A;
    int start0 = 0, length = 0, maximum = 0, p = 0;
    int start = 0, end = 0;

    for (int i = 0; i < n; ++i) {
        if (isdigit(A[i])) {
            continue;
        } else {
            if (isalpha(A[i]) || A[i] == '_') {
                start0 = i;
                length = 0;
                for (int k = i; k < n; ++k) {
                    if (isalnum(A[k]) || A[k] == '_') {
                        length++;
                    } else {
                        p = k;
                        break;
                    }
                    if (k == n - 1) {
                        i = n;
                        p = n;
                    }
                }
                if (length > maximum) {
                    end = p;
                    start = start0;
                    maximum = length;
                }
            }
        }
    }

    cout << A.substr(start, end - start) << endl;

    return 0;
}
