#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    long long int P[n][n];
    for(int i = 0; i < n; i++) {
        P[n - 1][i] = A[i];
    }
    //
    for(int j = n - 2; j >= 0; j--) {
        for(int i = 0; i <= j; i++) {
            P[j][i] = P[j + 1][i] + P[j + 1][i + 1];
        }
    }
    //
    for(int j = 0; j < n; j++) {
        for (int i = 0; i <= j; i++) {
            printf("%lld ", P[j][i]);
        }
        printf("\n");
    }
}
