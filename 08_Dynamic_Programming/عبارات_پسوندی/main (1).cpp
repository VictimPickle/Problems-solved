#include <iostream>
#include <stack>
using namespace std;
stack<int> value;
// stack <int> value;
// stack <char> ops;
void function(char a , int c , int b){
    if (a =='+')
        value.push(b + c);
    else if (a == '-')
        value.push(b - c);
    else if (a == '*')
        value.push(b*c);
    else
        value.push(int(b/c));
}
int evaluate(string a) {
    for(int i=0 ; i< a.length(); i++) {
        if (isdigit(a[i]))
            value.push(a[i] - '0');
        else {
            int b = value.top();
            value.pop();
            int c = value.top();
            value.pop();
            function(a[i], b , c);
        }
        // cout << value.top()<< endl;

    }

    return value.top();
}

int main() {
    string a;
    cin >> a;
    cout << evaluate(a);
    return 0;
}
