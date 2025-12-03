#include <stdio.h>
int main(){
    int string1=0 , string2=0 , sum1=0 , sum2=0 ,n , i , j;
    scanf("%d" , &n);
    for (i=0 ; n>=i ; ++i){
        scanf("%c" , &string1);
        sum1 += string1;
    }
    for (j=0 ; n>=j ; ++j){
        scanf("%c" , &string2);
        sum2 += string2;
    }
    if (sum1==sum2) printf("True");
    else printf("False");
}
