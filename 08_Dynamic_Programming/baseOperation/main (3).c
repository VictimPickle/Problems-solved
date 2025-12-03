#include <stdio.h>

void Base(long long int num,long long int base) {
    long long int newnum[10000];
    long long int i = 0;
    while (num > 0) {
        newnum[i] = num % base;
        i++;
        num /= base;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%lld", newnum[j]);
    }
}

int main() {
    long long int b, m , n;
    scanf("%lld%lld%lld", &b, &n , &m);
    long long int sum = m+n;
    long long int minus = n-m;
    long long int zarb = m*n;
    long long int taqsim = n/m;
    Base(sum, b);
    printf("\n");
    Base(minus, b);
    printf("\n");
    Base(zarb, b);
    printf("\n");
    Base(taqsim, b);
    return 0;
}
