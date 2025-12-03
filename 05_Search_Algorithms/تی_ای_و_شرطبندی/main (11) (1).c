#include <stdio.h>
#include <stdlib.h>

int main() {
    int door, tol, n, m = 0 , stoptime = 0 , speed = 0;
    scanf("%d %d %d", &door, &tol, &n);
    double *A = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &stoptime, &speed);
        A[i] = stoptime + (door * tol) / (double)speed;
    }
    double mn = A[0];
    int u = 0;
    for (int i = 1; i < n; i++) {
        if (mn > A[i]) {
            mn = A[i];
            u = i;
        }
    }
    printf("%d\n" , u + 1);
    free(A);
    return 0;
}
