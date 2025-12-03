#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *A = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j-1 < n; j++) {
            int l = i;
            int r = j;

            while (l < r) {
                sum += A[l];
                l++;
            }
        }
    }
    printf("%d", sum);
    free(A);
    return 0;
}
