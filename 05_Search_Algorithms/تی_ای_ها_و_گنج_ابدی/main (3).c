#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char **A = (char **) malloc(n * sizeof(char *));
    for (int i = 0; i < n; ++i) {
        A[i] = (char *) malloc(m * sizeof(char));
        scanf(" %s", A[i]);
    }

    int count = 0;
    for (int i = 1; i < n; i++) {

        for (int j = 0; j < m - 1; j++) {
            int amoodi = 0;
            int ofogi = 0;
            if (A[i][j] == '*' && A[i - 1][j] == '*' && A[i][j + 1] == '*') {

                for (int k = i; k >= 0; k--) {
                    if (A[k][j] == '*')
                        amoodi++;
                    else
                        break;
                }
                for (int k = j; k < m; k++) {
                    if (A[i][k] == '*')
                        ofogi++;
                    else
                        break;
                }

                for (int r = 2; r <= ofogi; r++) {
                    if (amoodi >= (2 * r))
                        count++;
                }
            }
        }

    }
    printf("%d\n", count);
}
