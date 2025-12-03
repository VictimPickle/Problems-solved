#include <bits/stdc++.h>
using namespace std;
long long int teams(const vector <int>& A ,int start, int end){
    if (end - start == 2)
        return A[start] + A[start + 1];

    int middle = (start + end) / 2;

    long long int max1 = *max_element(A.begin() + start , A.begin()+ middle);

    long long int max2 = *max_element(A.begin() + middle , A.begin() + end);

    long long int reward1 = max1 + teams(A , middle , end);

    long long int reward2 = max2 + teams(A , start , middle);

//    cout<<"reward1 is:"<<reward1<<endl<<"reward2 is:"<<reward2<<endl;

    return max(reward1 , reward2);

}
int main(){
    int n;
    cin >> n;
    vector<int> A;
    for (int i=0 ; i <pow(2 , n) ; i++){
        int x;
        cin >> x;
        A.push_back(x);
    }
    cout<< teams(A, 0, pow(2, n));

    return 0;
}
