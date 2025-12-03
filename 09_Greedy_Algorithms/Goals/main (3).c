#include <stdio.h>

int main() {
    int n , a ,b;
    scanf("%d%d%d" , &n , &a , &b);
    int A[1000];
    for(int i=0 ; i<n ; i++)
        scanf("%d" , &A[i]);
    int time1 = 45+a;
    int time2 = 90+b;
    int correct = 1;
    for(int i=0 ; i<n ; i++){
        /*
         * if(A[i]<=time1)
            count++;
        else if(A[i]<=time2 && A[i]>time1)
            count++;
        if(A[i+1]<A[i]){
            if (A[i] > time1)
                count--;
        */
        if(i+1<n){
            if (A[i]>A[i+1]){
                if (A[i] > time1){
                    correct = 0;
                }
        }
        }
        if (A[i] > time2)
            correct=0;

    }
    if(correct)
        printf("YES");
    else
        printf("NO");
}
