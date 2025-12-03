#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int precedence(const string& op) {
    if (op == "*" || op == "/") return 2;
    if (op == "+" || op == "-") return 1;
    return 0;
}

class BinaryTree {
    struct TreeNode {
        string value;
        float number;
        TreeNode* left;
        TreeNode* right;

        TreeNode(const string& val, float num = 0.0, TreeNode* l = nullptr, TreeNode* r = nullptr)
            : value(val), number(num), left(l), right(r) {}
    };

    TreeNode* root;

public:
    BinaryTree() : root(nullptr) {}

    void constructFromPostfix(const vector<string>& postfix) {
        vector<TreeNode*> nodes;
        for (const auto& token : postfix) {
            if (isOperator(token)) {
                TreeNode* rightNode = nodes.back();
                nodes.pop_back();
                TreeNode* leftNode = nodes.back();
                nodes.pop_back();

                float result = evaluate(token, leftNode->number, rightNode->number);
                TreeNode* node = new TreeNode(token, result, leftNode, rightNode);
                nodes.push_back(node);
            } else {
                nodes.push_back(new TreeNode(token, stof(token)));
            }
        }
        root = nodes.back();
    }

    float evaluateTree() const {
        return root ? root->number : 0.0;
    }

private:
    bool isOperator(const string& token) const {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    float evaluate(const string& op, float left, float right) const {
        if (op == "+") return left + right;
        if (op == "-") return left - right;
        if (op == "*") return left * right;
        if (op == "/") return left / right;
        return 0.0;
    }
};

vector<string> toPostfix(const vector<string>& infix) {
    vector<string> postfix;
    vector<string> operators;

    for (const auto& token : infix) {
        if (isdigit(token[0])) {
            postfix.push_back(token);
        } else if (token == "(") {
            operators.push_back(token);
        } else if (token == ")") {
            while (!operators.empty() && operators.back() != "(") {
                postfix.push_back(operators.back());
                operators.pop_back();
            }
            operators.pop_back(); // Remove "(" from stack
        } else {
            while (!operators.empty() && precedence(operators.back()) >= precedence(token)) {
                postfix.push_back(operators.back());
                operators.pop_back();
            }
            operators.push_back(token);
        }
    }

    while (!operators.empty()) {
        postfix.push_back(operators.back());
        operators.pop_back();
    }

    return postfix;
}

int main() {
    string input;
    cin >> input;

    vector<string> infix;
    string temp;

    for (char ch : input) {
        if (isdigit(ch)) {
            temp += ch;
        } else {
            if (!temp.empty()) {
                infix.push_back(temp);
                temp.clear();
            }
            infix.push_back(string(1, ch));
        }
    }
    if (!temp.empty()) {
        infix.push_back(temp);
    }

    vector<string> postfix = toPostfix(infix);

    for (const auto& token : postfix) {
        cout << token;
    }
    cout << endl;

    BinaryTree tree;
    tree.constructFromPostfix(postfix);

    cout << fixed << setprecision(3);
    cout <<tree.evaluateTree() << endl;

    return 0;
}
