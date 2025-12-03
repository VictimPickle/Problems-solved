#include <iostream>
#include <vector>
using namespace std;

long long int mergeSort(vector<int>& A, int left, int right, int middle, vector<int>& temp) {
    int i = left, j = middle + 1, t = left;
    long long int cnt = 0;
    while (i <= middle && j <= right) {
        if (A[i] <= A[j]) {
            temp[t] = A[i];
            t++;
            i++;
        } else {
            temp[t] = A[j];
            t++;
            j++;
            cnt += (middle - i + 1);
        }
    }
    while (i <= middle) temp[t++] = A[i++];
    while (j <= right) temp[t++] = A[j++];
    for (int k = left; k <= right; ++k)
        A[k] = temp[k];
    return cnt;
}

long long int merge(vector<int>& A, int left, int right, vector<int>& temp) {
    long long int cnt = 0;
    if (left < right) {
        int middle = left + (right - left) / 2;
        cnt += merge(A, left, middle, temp);
        cnt += merge(A, middle + 1, right, temp);
        cnt += mergeSort(A, left, right, middle, temp);
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    vector<int> temp(n);
    cout << merge(A, 0, n - 1, temp) << endl;
    return 0;
}
