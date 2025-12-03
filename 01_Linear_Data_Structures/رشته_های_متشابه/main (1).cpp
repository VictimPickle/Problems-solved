#include <bits/stdc++.h>
using namespace std;
int similar(string A , string B){
    if (A == B)
        return 1;
    if (A.length() % 2 != 0 || B.length() % 2 != 0 || A.length() != B.length()) {
        return 0;
    }
    string A1 , B1 , B2 , A2;
    A1 = A.substr(0 , A.length()/2);
    A2 = A.substr(A.length()/2 , A.length()/2);
    B1 = B.substr(0 , B.length()/2);
    B2 = B.substr(B.length()/2 , B.length()/2);
    if ((similar(A1 , B1)&& similar(A2 , B2)) || ((similar(A1 , B2)) && similar(A2 , B1)))
        return 1;
    else
        return 0;
}
int main() {
    string A , B;
    cin >> A >> B;
    string A1 , A2 , B1 , B2;

    if (similar(A , B))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
