#include<bits/stdc++.h>
using namespace std;

int main() {
    int n ;
    cin >> n;
    int A[n];
    for (int i=0 ; i<n ; i++){
        cin >> A[i];
    }
    int found = 0;
    for (int i=0 ; i<n ; i++){
        int x = 0;
        int j = i;
        while (j < n){
            x += A[j];
            j++;
            if (!x){
                found = 1;
                break;
            }
        }
    }
    if (found)
        cout<<1<<endl;
    else
        cout<<0<<endl;
    return 0;
}
