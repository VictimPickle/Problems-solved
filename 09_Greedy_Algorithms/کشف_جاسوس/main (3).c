#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    int *A = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int count = 0;
    int *left = &A[0];
    int *right = &A[n - 1];
    while(left<right){
        if (*right + *left > x) {
            count = count + (right - left);
            right--;
        }else{
            left++;
        }

    }
    printf("%d", count);

    free(A);
    return 0;
}
