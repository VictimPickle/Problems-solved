#include <stdio.h>
int main() {
    int n;
    int magic;
    scanf("%d %d ", &n, &magic);
    int A[100000];
    int B[100000];
    int C[100000];
    int D[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }
    /*for( int i = 0 ; i < n ; i++){
        scanf("%d" , C[i])
    }
     */
    for (int j = 0; j < n; j++) {
        C[j] = B[j] + magic;
    }
    for (int p = 0; p < n; p++) {
        D[p] = C[p] / A[p];
    }

    /*for (int u = 0; u < n; u++) {
        printf("%d" , D[u]);
        }
        */
    int min = D[0];
    for( int h = 0 ; h < n ; h++){
        if (D[h]< min)
            min = D[h];

    }
    printf("%d", min);
    }
