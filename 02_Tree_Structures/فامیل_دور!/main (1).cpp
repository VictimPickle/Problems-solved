#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    Node* insert(Node* root, int value) {
        if (!root) return new Node(value);
        if (value > root->data)
            root->right = insert(root->right, value);
        else
            root->left = insert(root->left, value);
        return root;
    }

    Node* Shajareh(Node* root, int a, int b) {
        if (!root) return nullptr;
        if (root->data > a && root->data > b)
            return Shajareh(root->left, a, b);
        if (root->data < a && root->data < b)
            return Shajareh(root->right, a, b);
        return root;
    }

    Node* Pth(Node* root, int value, int p) {
        vector<Node*> path;
        Node* current = root;

        while (current) {
            path.push_back(current);
            if (value < current->data)
                current = current->left;
            else if (value > current->data)
                current = current->right;
            else
                break;
        }

        if (path.size() < p) return nullptr;
        return path[path.size() - p];
    }
};

int main() {
    int n;
    cin >> n;

    LinkedList ll;
    vector<int> nodes(n);

    for (int i = 0; i < n; i++)
        cin >> nodes[i];

    int a, b, p;
    cin >> a >> b >> p;

    Node* root = nullptr;
    for (int i = 0; i < n; i++)
        root = ll.insert(root, nodes[i]);

    Node* x = ll.Shajareh(root, a, b);
    // cout<<"X is :"<<x-> data<<endl;
    if (!x) {
        cout << -1 << endl;
        return 0;
    }
    // cout<<"At least we are here"<<endl;
    Node* ancestor = ll.Pth(root, x->data, p);

    if (ancestor)
        cout << ancestor->data << endl;
    else
        cout << -1 << endl;

    return 0;
}
