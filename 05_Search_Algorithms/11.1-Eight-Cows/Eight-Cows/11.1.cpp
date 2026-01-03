#include <bits/stdc++.h>
using namespace std;
#define WTF cout << "WTF"
#define END exit(0)
#define elif else if
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0)
#define CinArr(arr, n) for(int i = 0; i < n; i++) cin >> arr[i]
#define CinArrK(arr, n , k) for(int i = k; i < n; i++) cin >> arr[i]
#define Sort(a) sort(a.begin(), a.end())
#define FOR(a) for(int i = 0; i < a; i++)
typedef long long ll;
typedef pair<ll, ll> PLL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<long long> VLL;

vector<string> cows = {"Beatrice", "Bella", "Belinda", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
vector<pair<string, string>> constraints;

bool isValid(vector<string>& perm) {
    map<string, int> pos;
    for(int i = 0; i < 8; i++) {
        pos[perm[i]] = i;
    }
    for(auto& c : constraints) {
        int p1 = pos[c.first];
        int p2 = pos[c.second];
        if(abs(p1 - p2) != 1) return false;
    }
    return true;
}

int main() {
    IOS; CT;
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cow1, cow2, dummy;
        ss >> cow1 >> dummy >> dummy >> dummy >> dummy >> cow2;
        constraints.push_back({cow1, cow2});
    }
    sort(cows.begin(), cows.end());
    do {
        if(isValid(cows)) {
            for(auto cow : cows) cout << cow << " ";
            break;
        }
    } while(next_permutation(cows.begin(), cows.end()));
    return 0;
}
