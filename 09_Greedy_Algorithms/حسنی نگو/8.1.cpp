#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n , k;  cin >> n >> k;
    ll A[n];
    for(int i = 0 ; i < n ; i++)    cin>>A[i];
    int cnt = 0 ;
    int i = 0;
    while(i < n ){
        int sum = 0;
        while(sum <= k){
            sum += A[i];
            i++;
        }
        if(sum > k){
            i--;
            sum -= A[i];
        }
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;

}