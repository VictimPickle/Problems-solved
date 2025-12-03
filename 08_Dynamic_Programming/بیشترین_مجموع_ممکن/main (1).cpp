#include <iostream>
#include <vector>
using namespace std;
int MaxSum(vector<int> A){
    int q = A[0];
    for (int i = 0; i < A.size(); i++) {
        int x = 0;
        for (int j = i; j < A.size(); j++) {
            x += A[j];
        }
        q = max(q, x);
    }
    return q;
}

int main() {
    vector<int> A;
    int num;
    while (cin >> num) {
        A.push_back(num);
    }
    cout << MaxSum(A);
    return 0;
}
