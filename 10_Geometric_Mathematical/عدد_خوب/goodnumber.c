#include <stdio.h>
int main(){
    int vroody , h ;
    scanf("%d" , &vroody);
    for (int a=1 ; a ; a++){
        int n = a*(a+1)/2;
        int c = 0 ;
        for(int i = 1 ; i<=n ; i++){
            if (n%i==0) c++;
        }
        h=n;
        if (c==vroody) break;
    }
    printf("%d" , h );
    return 0 ;
}
