#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <utility>
using namespace std;

using par = pair<long long,long long>;
static vector<par> A;
struct Best{
    long long d;
    int a , b;
    Best(): d(LLONG_MAX), a(-1), b(-1) {}
};
inline void upd(Best &best,int i,int j){
    if(i==j) return;
    long long dx = A[i].first  - A[j].first;
    long long dy = A[i].second - A[j].second;
    long long d  = dx*dx + dy*dy;
    if(d < best.d){ best.d = d; best.a = i; best.b = j; }
}

inline bool cmpX(int i,int j){
    if(A[i].first != A[j].first) return A[i].first < A[j].first;
    return A[i].second < A[j].second;
}

inline bool byYthenX(int i,int j){
    if(A[i].second != A[j].second) return A[i].second < A[j].second;
    return A[i].first  < A[j].first;
}

void solve(vector<int>& idx,int l,int r,vector<int>& tmp,Best& best){
    int n = r - l;
    if(n <= 8){
        for(int u=l; u<r; ++u)
            for(int v=u+1; v<r; ++v)
                upd(best, idx[u], idx[v]);

        sort(idx.begin()+l , idx.begin()+r , byYthenX);
        return;
    }

    int m = l + n/2;
    long long midx = A[idx[m]].first;

    solve(idx, l, m, tmp, best);
    solve(idx, m, r, tmp, best);

    int i=l, j=m, k=0;
    while(i<m && j<r){
        if( A[idx[i]].second < A[idx[j]].second ||
           (A[idx[i]].second == A[idx[j]].second && A[idx[i]].first < A[idx[j]].first) )
            tmp[k++] = idx[i++];
        else
            tmp[k++] = idx[j++];
    }
    while(i<m) tmp[k++] = idx[i++];
    while(j<r) tmp[k++] = idx[j++];
    for(int t=0; t<k; ++t) idx[l+t] = tmp[t];

    vector<int> strip;
     strip.reserve(n);
    for(int p=l; p<r; ++p){
        int id = idx[p];
        long long dx = A[id].first - midx;
        if(dx*dx < best.d){
            for(int q=(int)strip.size()-1, cnt=0; q>=0 && cnt<7; --q, ++cnt)
                upd(best, id, strip[q]);
            strip.push_back(id);
        }
    }
}

int main(){
    int T; 
    cin >> T;
    while(T--){
        int n; cin>>n;
        A.resize(n);
        for(int i=0;i<n;++i){
            long long x,y; cin>>x>>y;
            A[i] = {x,y};
        }
        vector<int> B(n);
        for(int i=0;i<n;++i) B[i]=i;      
        sort(B.begin(), B.end(), cmpX);   
        vector<int> tmp(n);
        Best best;
        solve(B, 0, n, tmp, best);

        double xm = (A[best.a].first  + A[best.b].first ) / 2.0;
        double ym = (A[best.a].second + A[best.b].second) / 2.0;
        cout<<fixed<<setprecision(3)<<xm<<' '<<ym<<"\n";
    }
    return 0;
}
