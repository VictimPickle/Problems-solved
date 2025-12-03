#include <stdio.h>
long long int fibo(int n, int k) {
    if (n <= k - 1) {
        return n;
    }else{
        long long int result = 0;
        for (int i = 1; i <= k; i++) {
            result += fibo(n - i, k);
        }
        return result;
    }
}
int main() {
    int n, k;
    scanf("%d%d", &n , &k);
    long long int result = fibo(n, k);
    printf("%lld" , result);
    return 0;
}
