#include<bits/stdc++.h>
using namespace std;

void shifting(string &A, int i) {
    for (int j = i; j < A.length() - 1; j++) {
        A[j] = A[j + 1];
    }
    A.pop_back();
}

int main() {

    string A, B;
    cin >> A >> B;
    string C = "";
    string D = "";
    int k = A.length();
    int m = B.length();
    if (B.find(A) != string::npos) {
        cout << B;
        return 0;
    }
    else if (A.find(B) != string::npos) {
        cout << A;
        return 0;
    }
    int j=A.length();
    for (int i=0 ; i<A.length() ; i++){
        if (A.substr(i , k - i) == B.substr(0 , k-i)){
//            cout<<A.substr(i , k-i)<<endl;
            j = i;
            break;
        }
    }
    for (int i=0 ; i<j ; i++){
        C += A[i];
    }
    C += B;
    j=B.length();
    for (int i=0 ; i<B.length() ; i++){
        if (B.substr(i , m - i) == A.substr(0 , m-i)){
//            cout<<A.substr(i , k-i)<<endl;
            j = i;
            break;
        }
    }
    for (int i=0 ; i<j ; i++){
        D += B[i];
    }
    D += A;
//    cout<<C<<endl;
    if (D.length() > C.length()) {
        cout << C;
    }
    else if (C.length() > D.length())
        cout << D;
    else{
        if (tolower(D[0]) > tolower(C[0]))
            cout << C;
        else
            cout << D;
    }
    return 0;
}
