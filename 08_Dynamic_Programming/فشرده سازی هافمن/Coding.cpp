#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>

using namespace std;
//inja node haro dorost maikonam
struct TNode {
    char c;
    int f;
    TNode* l;
    TNode* r;

    TNode(char x, int y) : c(x), f(y), l(nullptr), r(nullptr) {}
    TNode(int y) : c('\0'), f(y), l(nullptr), r(nullptr) {}
};
// vase priority que
struct Cmp {
    bool operator()(TNode* a, TNode* b) {
        return a->f > b->f;
    }
};
//dorost kardan
void gen(TNode* n, string s, unordered_map<char, string>& m) {
    if (!n) return;
    if (!n->l && !n->r) {
        m[n->c] = s;
        return;
    }
    gen(n->l, s + "0", m);
    gen(n->r, s + "1", m);
}
// decode kardan
string dec(TNode* n, const string& e) {
    string d;
    TNode* t = n;
    for (int i = 0; i < e.length(); i++) {
        if (e[i] == '0') {
            t = t->l;
        } else {
            t = t->r;
        }
        if (!t->l && !t->r) {
            d += t->c;
            t = n;
        }
    }
    return d;
}

int main() {
    string t, e;
    cin >> t >> e;

    unordered_map<char, int> fm;
    for (int i = 0; i < t.length(); i++) {
        fm[t[i]]++;
    }

    priority_queue<TNode*, vector<TNode*>, Cmp> pq;
    for (auto it = fm.begin(); it != fm.end(); ++it) {
        pq.push(new TNode(it->first, it->second));
    }
    // hamoon care yeki kardan
    while (pq.size() > 1) {
        TNode* a = pq.top();
        pq.pop();
        TNode* b = pq.top();
        pq.pop();
        TNode* c = new TNode(a->f + b->f);
        c->l = a;
        c->r = b;
        pq.push(c);
    }

    TNode* root = pq.top();

    unordered_map<char, string> codes;
    gen(root, "", codes);

    cout << dec(root, e) << endl;
    return 0;
}
