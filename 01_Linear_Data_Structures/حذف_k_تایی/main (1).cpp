#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> a;
stack<int> b;
vector<int> A;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    int k;
    cin >> k;
    int j;
    for(int i= 0 ; i < n ; i++) {
        if(k == 0) {
            j = i;
            break;
        }
        if(a.empty()) {
            a.push(A[i]);
        }
        else{
            if(A[i] > a.top()) {
                a.pop();
                k--;
                while( k != 0 && !a.empty()) {
                    if(A[i] > a.top()) {
                        a.pop();
                        k--;
                    }
                    else
                        break;
                }
                a.push(A[i]);
            }
            else {
                a.push(A[i]);
            }
        }

    }
    while (!a.empty()) {
        b.push(a.top());
        a.pop();
    }
    while(!b.empty()) {
        cout<<b.top()<<" ";
        b.pop();
    }
    for(int q = j; q < n ; q++) {
        cout << A[q]<<" ";
    }
    return 0;
}
