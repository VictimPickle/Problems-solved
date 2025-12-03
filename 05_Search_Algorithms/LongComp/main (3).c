#include <stdio.h>
int power(int m , int n){
    int ans = 1;
    if(n==0){
        return 1;
    }
    else{
        while(n>0){
            ans *= m;
            n--;
        }
        return ans;
    }

}
int main(){
    int t;
    scanf("%d" , &t);
    for(int i=0 ; i<t ; i++){
        int p1 , p2 , x1 , x2;
        scanf("%d %d %d %d" , &x1 , &p1 , &x2 , &p2);
        long long  n1 , n2;
        n1 = x1 * power(10 , p1);
        n2 = x2 * power(10 , p2);
        if(n1>n2)
            printf(">\n");
        else if(n2>n1)
            printf("<\n");
        else
            printf("=\n");

    }
}