#include <iostream>
#include <string>

using namespace std;

string LF(int n, int i = 1) {
    if (n == 0) return to_string(i);
    return to_string(i) + "+\\frac{" + LF(n - 1, i * 2) + "}{" + LF(n - 1, i * 2 + 1) + "}";
}

int main() {
    int n;
    cin >> n;
    cout << LF(n - 1);
    return 0;
}
