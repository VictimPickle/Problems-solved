#include <stdio.h>
int count(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return count(n - 1, k - 1) + count(n - 1, k);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int result = count(n, k);
    printf("%d" , result);

    return 0;
}
