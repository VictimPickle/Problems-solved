#include <stdio.h>
#include <stdlib.h>
void swapStrings(char *a, char *b) {
    while (*a != '\0' || *b != '\0') {
        char temp;
        temp = *a;
        *a = *b;
        *b = temp;
        a++;
        b++;
    }
}
int main() {
    int n;
    scanf("%d", &n);

    char **A = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        A[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", A[i]);
    }

    int B[1000];
    int m = 0;
    char temp;
    char temp1;
    for (int i = 0; i < n; i++) {
        int length = 0;
        while (A[i][length] != '\0') {
            length++;
        }
        B[m] = length;
        m++;
    }
    for(int j=0 ; j<n ; j++){
        for(int i=j+1 ; i<n ; i++){
            if (B[i]<B[j]){
                temp = B[i];
                B[i] = B[j];
                B[j] = temp;
                swapStrings(A[i] , A[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s ", A[i]);
    }
}
