#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int searchValue(vector<int>& in, int value, int s, int e) {
    for (int i = s; i <= e; i++) {
        if (in[i] == value)
            return i;
    }
    return -1;
}

Node* buildTreeRecur(vector<int>& in, vector<int>& pre, int &preIndex, int s, int e) {
    if (s > e) return nullptr;
    Node* root = new Node(pre[preIndex]);
    preIndex++;
    int index = searchValue(in, root->data, s, e);
    root->left = buildTreeRecur(in, pre, preIndex, s, index - 1);
    root->right = buildTreeRecur(in, pre, preIndex, index + 1, e);
    return root;
}

Node* buildTree(vector<int>& in, vector<int>& pre) {
    int preIndex = 0;
    return buildTreeRecur(in, pre, preIndex, 0, in.size() - 1);
}

int summm(Node* x) {
    if (!x)
        return 1000;
    if(x->left && x->right)
        return x->data + summm(x->left) + summm(x->right);
    if(!x->left && x->right)
        return  x->data +summm( x->right);
    if(x->left && !x->right)
        return x->data + summm(x->left);
    else
        return x->data;

}

void Justice(Node* x, int &count) {
    if (!x)
        return;
    int leftSum = summm(x->left);
    int rightSum = summm(x->right);
    if (leftSum == rightSum && (x->left || x->right)) {
        count++;
    }
    Justice(x->left, count);
    Justice(x->right, count);
}

int main() {

        int n;
        cin >> n;
        vector<int> in(n), pre(n);
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> pre[i];
        }
        Node* root = buildTree(in, pre);
        int count = 0;
        Justice(root, count);
        cout << count << endl;
        // cin>>y;

    return 0;
}
