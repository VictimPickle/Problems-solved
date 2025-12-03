#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int q;
    cin >> q;
    
    while (q--) {
        int n;
        cin >> n;
        
        vector<int> t(n);
        for (int i = 0; i < n; ++i) {
            cin >> t[i];
        }
        
        sort(t.begin(), t.end());
        
        int total_loss = 0;
        for (int i = 0; i < n; ++i) {
            total_loss += abs(t[i] - (i + 1));
        }
        
        cout << total_loss << endl;
    }
    
    return 0;
}
