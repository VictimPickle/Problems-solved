#include<bits/stdc++.h>
using namespace std;

int main() {
    string A, B;
    cin >> A;
    cin >> B;

    int j = 0;
    int maxCount = 0;
    int m = B.size();

    for (int i = 0; i <= A.length() - m; i++) {
        if (A.substr(i, m) == B) {
            int k = i;
            int count = 0;
            while (i <= A.length() - m && A.substr(i, m) == B) {
                count++;
                i += m;
            }
            i -= m;
            if (count > maxCount) {
                maxCount = count;
                j = k;
            }
        }
    }

    cout << maxCount << endl << j << endl;

    return 0;
}
