#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int n;
    scanf("%d", &n);
    char *A = (char *)malloc(100000 * sizeof(char));
    scanf("%s", A);
    int len = strlen(A);
    int j = 0;
    for (int i = 0; i < len; i++) {
        while (A[i] == '=') {
            if (j > 0) {
                j--;
            }
            i++;
        }
        if (i < len) {
            A[j++] = A[i];
        }
    }
    A[j] = '\0';
    printf("%s\n", A);
    free(A);
    return 0;
}
