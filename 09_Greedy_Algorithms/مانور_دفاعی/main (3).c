#include <stdio.h>
#include <string.h>
int func(int A[] , int n , int q , int w, int sum){
    if(q == sum/2 || w == sum/2) {
        return 1;
    }
    if (q > sum/2 || w>sum/2){
        return 0;
    }
    if(A[n] == A[n-1]){
        n-=2;
    }
    if(n == 0) {
        return 0;
    }
    if(func(A, n-1, q+A[n-1], w, sum)==1 || func(A, n-1, q, w+A[n-1], sum) == 1){
        return 1;
    }
    return 0;
}
int main(){
    int n;
    scanf("%d", &n);
    int A[10000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    if (sum%2 == 1) {
        printf("NO");
    }else{
        if (func(A, n, 0, 0, sum)==1)
            printf("YES");
        else{
            printf("NO");
        }
    }
}
