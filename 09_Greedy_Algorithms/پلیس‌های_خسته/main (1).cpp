#include <iostream>
#include <vector>
using namespace std;\
const int maxn = 1e5+7;
vector<int> a[maxn];
char c[maxn];
int ans[maxn];
int main() {
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        cin>>c[i];
    }
    for(int i=0;i<n;i++) {
        if(c[i] == 'T') {
            for(int j=i;j<=(i+k);j++) {
                if(c[j%n] == 'P')
                    a[i].push_back(j%n);
            }
            for(int j=i;j>=(i-k);j--) {
                if(c[(j+n)%n] == 'P')
                    a[i].push_back((j+n)%n);
            }
        }
    }
    for(int i=0;i<n;i++) {
        if(a[i].size())
            for(int j=0;j<a[i].size();j++)
                ans[a[i][j]]=1;
    }
    int t=0;
    for(int i=0;i<n;i++)
        if(c[i] == 'T')
            t++;
    int Ans=0;
    for(int i=0;i<n;i++)
        Ans+=ans[i];
    cout<<min(Ans,t);

    return 0;
}
