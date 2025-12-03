#include <stdio.h>
#include <math.h>
int main(){
    int y , x , i=1 , j=1 , k , l ,  m , n ;
    scanf("%d%d" , &y , &x);
    for (i ; y>=i ;i++){
        if(i%2==0){
            k=x*i;
            m=k;
            for(k ; k>m-x ; k--){
                printf("%d "  , k);
            }
        }else{
        l=x*(i-1)+1;
        n=l;
        for (l;n+x>l;l++){
            printf("%d ", l);
        }
        }
        if (i!=y) printf("\n");

    }

    return 0;




}
