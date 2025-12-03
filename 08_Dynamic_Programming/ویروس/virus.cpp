#include <bits/stdc++.h>
using namespace std;

bool contains(const string& a, const string& b) {
    if (b.size() > a.size()) return false;
    for (size_t i = 0; i + b.size() <= a.size(); i++) {
        bool ok = true;
        for (size_t j = 0; j < b.size(); j++) {
            if (a[i + j] != b[j]) { ok = false; break; }
        }
        if (ok) return true;
    }
    return false;
}

int overlap(const string& a, const string& b) {
    int mx = min(a.size(), b.size());
    for (int k = mx; k >= 0; k--) {
        bool ok = true;
        for (int i = 0; i < k; i++) {
            if (a[a.size() - k + i] != b[i]) { ok = false; break; }
        }
        if (ok) return k;
    }
    return 0;
}

string merge2(const string& a, const string& b) {
    if (contains(a, b)) return a;
    int k = overlap(a, b);
    return a + b.substr(k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2, s3;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);

    vector<string> s = {s1, s2, s3};

    vector<int> perm = {0, 1, 2};
    int best = INT_MAX;

    sort(perm.begin(), perm.end());
    do {
        string t = s[perm[0]];
        t = merge2(t, s[perm[1]]);
        t = merge2(t, s[perm[2]]);
        best = min(best, (int)t.size());
    } while (next_permutation(perm.begin(), perm.end()));

    cout << best << "\n";
    return 0;
}
