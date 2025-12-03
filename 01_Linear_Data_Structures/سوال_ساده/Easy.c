#include <stdio.h>
int main(){
    int n;
    int A[10000];
    scanf("%d" , &n);
    for (int i=0 ; i<n ; i++){
        scanf("%d" , &A[i]);
    }
    double sum = 0;
    for (int j=0 ; j<n ; j++){
        sum += A[j];
    }
    double Avg = sum/n;
    double max = A[0];
    for (int m=0 ; m<n ; m++){
        if (max<A[m]){
           max=A[m];
    }
    }
    double min = A[0];
    for (int l=0 ; l<n ; l++){
        if (min>A[l]){
            min = A[l];
        }
    }
    printf("%.6lf\n", sum);
    printf("%.6lf\n", Avg);
    printf("%.6lf\n", max);
    printf("%.6lf\n", min);





}
