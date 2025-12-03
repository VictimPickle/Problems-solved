#include<bits/stdc++.h>
using namespace std;
void simplization (vector<char> A , int n){
    bool Correct = true;
    for (int i= 0 ; i<n-1 ; i++){
        if (A[i] == A[i+1]){
            A.erase(A.begin() + i);
            A.erase(A.begin() + i);
            Correct = false;
            break;
        }
    }
    if (!Correct)
        simplization(A , n - 2);
    else{
        for(int i =0 ; i<A.size() ; i++){
            cout << A[i] << "";
        }
    }
}
int main(){
    vector<char> A;
    int n;
    cin >> n;
    for (int i =0 ; i< n ; i++){
        char x;
        cin>> x;
        A.push_back(x);
    }
    simplization(A , n);
}
