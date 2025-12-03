#include <stdio.h>
int main()
{
    int i , j ,n , a, b , c , d;
    scanf("%d" , &n);
    i = 1;
    j = n-i;
    for (i , j ; n>=i ; i++,j--){
        for (a=1 ; j>=a ;a++){
            printf(" ");
        }
        for (b=1 ; i>=b ; b++){
            printf("* ");
        }
        printf("\n");
    }
    i=n ; j=0;
    for (i , j ; i>=0 ; i-- , j++){
        for (c=1;j>=c ; c++){
            printf(" ");
        }
        for(d=1 ; i>=d ; d++){
            printf("* ");
        }
        printf("\n");
    }
    return 0 ;
    }
