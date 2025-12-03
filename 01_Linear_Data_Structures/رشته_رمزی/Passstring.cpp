#include <bits/stdc++.h>
using namespace std;

string cleanLine(string s) {
    string t;
    for (char c : s) if (c != ' ' && c != '\t' && c != '\r') t.push_back(c);
    return t;
}

bool dfs(int i, int j, const string& s, const string& p,
         unordered_map<char,string>& mp, unordered_set<string>& used) {
    int n = (int)s.size(), m = (int)p.size();
    if (j == m) return i == n;
    if (i == n) return false;

    char c = p[j];
    auto it = mp.find(c);
    if (it != mp.end()) {
        const string& w = it->second;
        int L = (int)w.size();
        if (i + L > n) return false;
        for (int k = 0; k < L; k++) if (s[i + k] != w[k]) return false;
        return dfs(i + L, j + 1, s, p, mp, used);
    } else {
        int rem = m - (j + 1);
        int maxL = n - i - rem;
        for (int L = 1; L <= maxL; L++) {
            string w = s.substr(i, L);
            if (used.count(w)) continue;
            mp[c] = w;
            used.insert(w);
            if (dfs(i + L, j + 1, s, p, mp, used)) return true;
            used.erase(w);
            mp.erase(c);
        }
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    string s, p;
    getline(cin, s);

    while (T--) {
        getline(cin, s);
        getline(cin, p);
        s = cleanLine(s);
        p = cleanLine(p);

        unordered_map<char,string> mp;
        unordered_set<string> used;
        cout << (dfs(0, 0, s, p, mp, used) ? "Yes" : "No") << "\n";
    }
    return 0;
}
