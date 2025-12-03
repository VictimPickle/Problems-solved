#include <stdio.h>
int main(){
    int n , b , t , a;
    scanf("%d %d" , &n , &b);
    t = n%b;
    a = b-t;
    printf("%d" , a);
    return 0;


}
