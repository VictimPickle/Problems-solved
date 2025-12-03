#include <bits/stdc++.h>
using namespace std;
int main(){
    string A ;
    cin >> A;
    int n = A.length();
    int maxim = 0;
    for(int i= 0 ; i< n ; i++){
       
        if (A[i] == '0'){
            // cout<<"Hi Baby!!\n";
            int x = 0;
            while(A[i] == '0'){
                x ++;
                i++;
            }
            i--;
            maxim = max(maxim , x);
        }
        else
            continue;
    }
    cout << maxim;

}
