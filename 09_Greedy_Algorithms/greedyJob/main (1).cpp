#include <bits/stdc++.h>
using namespace std;
struct Job{
    int start;
    int end;
};
bool compare(Job a ,Job  b){
    return (a.end < b.end);
}
int main() {
    int n;
    cin >> n;
    vector<Job> times(n) ;
    for(int i=0 ; i< n ; i++){
        cin >> times[i].start >> times[i].end;
    }
    sort(times.begin() , times.end() , compare);
    int count =0 ;
    int LE = 0;
    for (int i=0 ; i<n ; i++){
        if (times[i].start >= LE){
            count++;
            LE = times[i].end;
        }
    }
    cout << count <<endl;
    return 0;
}
