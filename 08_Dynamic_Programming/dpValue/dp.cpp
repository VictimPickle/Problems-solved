#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, s;
    cin >> n;
    
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    cin >> s;
    
    vector<int> dp(s + 1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j <= s; ++j) {
            if (dp[j - coins[i]] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }
    
    if (dp[s] == INT_MAX) {
        cout << "No solution" << endl;
    } else {
        vector<int> result(n, 0);
        int remaining = s;
        
        while (remaining > 0) {
            for (int i = 0; i < n; ++i) {
                if (remaining >= coins[i] && dp[remaining] == dp[remaining - coins[i]] + 1) {
                    result[i]++;
                    remaining -= coins[i];
                    break;
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
