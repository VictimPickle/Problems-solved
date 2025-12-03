#include <stdio.h>
int main(){
    long int a , b , c , d;
    scanf("%ld %ld" , &a , &b);
    c =(~b)+1;
    d = c+a;
    printf("%ld" , d);
    return 0;



}
