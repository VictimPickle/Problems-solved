#include <stdio.h>
#include <string.h>

void sorting(char A[100]){
    for(int i=0 ; i<strlen(A) ;i++){
        for(int j=i+1 ; j<strlen(A) ; j++){
            if(A[j]<A[i]){
                char temp;
                temp = A[i];
                A[i]=A[j];
                A[j]=temp;
            }else if (A[j] == A[i])
                continue;
        }
    }
    return;
}

int main() {
    char A[100];
    scanf("%s" , A);
    char B[100];
    scanf("%s" , B);
    sorting(A);
    sorting(B);
    int m=0 , n=0;
    char C[2000];
    int b = strlen(A) + strlen(B);
    for(int i=0 ; i<b; i++){
        if(m==strlen(A)){
            C[i] = B[n++];
        }
        else if(n==strlen(B)){
            C[i] = A[m++];
        }
        else if(A[m]<B[n]){
            C[i] = A[m++];
        }
        else if(A[m]>B[n]){
            C[i] = B[n++];
        }
        else if(A[m]==B[n]){
            C[i++] = A[m++];
            C[i] = B[n++];
        }
    }
    C[b] = '\0';
    printf("%s\n" , C);
}
