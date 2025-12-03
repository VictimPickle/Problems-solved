#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> startAt(100001);
    int maxR = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        startAt[l].push_back(r);
        maxR = max(maxR, r);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= maxR; i++){
        for (int r : startAt[i]) pq.push(r);
        if (!pq.empty() && pq.top() < i){
            cout << "NO"<<endl;
            return 0;
        }
        for (int j = 0; j < k && !pq.empty(); j++){
            pq.pop();
        }
    }
    if(pq.empty())  cout<<"YES"<<endl;
    else    cout<<"NO"<<endl;
    return 0;
}
