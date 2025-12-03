#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);
    int *A = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    int count = 0;
    for(int i = 0; i < n; i++) {
        int max_temp = A[i];
        for(int j = i; j < n; j++) {
            if(A[j] > max_temp)
                max_temp = A[j];
            if(max_temp <= q && j - i + 1 >= k)
                count++;
        }
    }

    printf("%d", count);

    free(A);
    return 0;
}
