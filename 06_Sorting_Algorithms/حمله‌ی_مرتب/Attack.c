#include<stdio.h>
int main(){
    int m ,n , i , j , t , k;
    int A[9000] , B[9000];
    scanf("%d" , &m);

    for (i=0 ; i<m ; i++){
        scanf("%d",&A[i]);
    }
    scanf("%d" , &n);
    for (j=0 ; j<n ; j++){
        scanf("%d" ,&B[j]);
    }
    i=0;
    j=0;
    for(t=1 ; t<=m+n ; t++){
        if (i==m&&j==n)
            break;
        if (i==m){
            printf("%d " , B[j]);
            j++;
            continue;
        } else if (j==n){
            printf("%d " , A[i]);
            i++;
            continue;
        }
        if (A[i]<B[j]){
            printf("%d " , A[i]);
            i++;
        }else if(A[i]==B[j]){
            printf("%d %d " , A[i] , B[j]);
            i++;
            j++;
        }else{
            printf("%d " ,B[j]);
            j++;
        }


    }
}
