#include <stdio.h>

void fillSpiral(int A[10][10], int n, int radif1, int sotoon1, int radif2, int sotoon2, int num) {
    if (radif1 > radif2 || sotoon1 > sotoon2)
        return;

    for (int i = sotoon1; i <= sotoon2; i++)
        A[radif1][i] = num;

    for (int j = radif1; j <= radif2; j++)
        A[j][sotoon2] = num;

    for (int i = sotoon2 ; i >= sotoon1; i--)
        A[radif2][i] = num;

    for (int j = radif2 ; j > radif1; j--)
        A[j][sotoon1] = num;

    A[radif1 + 1][sotoon1]= 1-num;
    if (n==4 || n==8){
        if (radif2 - radif1 == 1){
            A[radif1][sotoon2]=0;
            A[radif1][sotoon1]=0;
            A[radif2][sotoon2]=0;
            A[radif2][sotoon1]=0;
            return;
        }
    }

    fillSpiral(A, n, radif1 + 1, sotoon1 + 1, radif2 - 1, sotoon2 - 1, 1 - num);
}

int main() {
    int n;
    int A[10][10];
    scanf("%d", &n);
    for (int p = 0; p < n; p++) {
        for (int i = 0; i < n; i++) {
            A[p][i] = 0;
        }
    }
    fillSpiral(A, n, 0, 0, n - 1, n - 1, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d", A[i][j]);
        printf("\n");
    }

    return 0;
}