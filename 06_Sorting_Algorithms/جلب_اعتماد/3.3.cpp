#include<bits/stdc++.h>
using namespace std;
vector<int> margesort(int l, int r , string algo, int &p){
    if (r - l == 1)
        return {l};
    int m = (l+r)/2;
    vector<int> L = margesort(l , m, algo , p);
    vector<int>R = margesort(m , r, algo , p);
    vector<int> res;
    int i=0 , j = 0 ;
    while(i<L.size() and j < R.size()){
        if(algo[p] == '1'){
            res.push_back(L[i]);
            i++;
        }else{
            res.push_back(R[j]);
            j++;
        }
        p++;
    }
    while(i < L.size()){
        res.push_back(L[i]);
        i++;
    }
    while(j < R.size()){
        res.push_back(R[j]);
        j++;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    string algo;
    cin >> algo;
    int p = 0  ;
    vector<int> res = margesort(0 , n, algo , p);
    // for(int i :res) cout<<i <<" ";
    vector<int> A(n);
    for(int i = 1 ; i <= n ;i++)    A[res[i-1]] = i;
    long long mod = 1000003;
    long long sum = 1;
    for(int i = 0 ; i < n ; i++)    sum = (31 * sum + A[i])%mod;
    cout<<sum<<endl;
    return 0;

}