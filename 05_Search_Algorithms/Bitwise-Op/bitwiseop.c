#include <stdio.h>
#include <math.h>
int main(){
    long int a , b , c , a1 , b1 , c1 ;
    scanf("%ld %ld %ld" , &a , &b , &c );
    a1 = a&b;
    b1 = a&c;
    c1 = b&c;
    printf("%ld %ld %ld" , a1 , b1 , c1);

    return 0;








}
