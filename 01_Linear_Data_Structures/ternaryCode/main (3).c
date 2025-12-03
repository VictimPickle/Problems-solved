#include <stdio.h>
int main() {
    char A[300];
    int i;
    for(i=0 ; i<300 ; i++){
        scanf("%c" , &A[i]);
        if (A[i]=='\n')
            break;
    }
    int b = i;
    for(i=0 ; i<b ; i++){
        if(A[i] == '.'){
            printf("0");
        }
        else if (A[i] == '-'){
            if (A[i+1] == '-') {
                printf("2");
                i++;
            }
            else if(A[i+1] == '.') {
                printf("1");
                i++;
            }
        }
    }
    return 0;
}
