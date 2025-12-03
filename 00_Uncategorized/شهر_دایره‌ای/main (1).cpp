#include <bits/stdc++.h>
using namespace std;
int main() {
    int n , m;
    cin >> n >> m;
    int N[n];
    for (int i=0 ; i<n ; i++){
        cin>> N[i];
    }
    int M[m];
    for(int i=0 ; i< m ; i++)
        cin >> M[i];
    bool found = false;
    int q = N[0];
    for (int i=0 ; i<n ; i++){
        if (N[i] != q){
            found = true;
            break;
        }
    }
    if (found){
        q = M[0];
        for (int i=0 ; i<m ; i++){
            if (M[i] != q){
                found = true;
                break;
            }
        }
    }
    if (found)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
