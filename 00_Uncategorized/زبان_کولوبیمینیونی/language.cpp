#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

unordered_map<string, vector<string>> grammar;

bool is_valid_word(const string& variable, const string& word) {
    if (word.empty()) return false;
    if (grammar.find(variable) == grammar.end()) {
        return word == variable; // If variable doesn't exist in grammar, match it directly
    }

    for (const string& rule : grammar[variable]) {
        int pos = 0;
        bool match = true;
        for (char c : rule) {
            if (c >= 'a' && c <= 'z') { // Letter
                if (pos < word.size() && word[pos] == c) {
                    pos++;
                } else {
                    match = false;
                    break;
                }
            } else { // Variable
                if (pos < word.size() && is_valid_word(string(1, c), word.substr(pos))) {
                    break;
                } else {
                    match = false;
                    break;
                }
            }
        }
        if (match) return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string variable, rule;
        cin >> variable;
        getline(cin, rule);
        stringstream ss(rule);
        string sub_rule;
        while (ss >> sub_rule) {
            grammar[variable].push_back(sub_rule);
        }
    }

    string word;
    cin >> word;

    if (is_valid_word("S", word)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
