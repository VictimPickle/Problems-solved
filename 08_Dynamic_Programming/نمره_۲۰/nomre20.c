#include <stdio.h>
int main(){
    char B[1000];
    int n , k , i ,j , last ;
    scanf("%d" , &n);
    scanf("%d" , &k);
    scanf("%s" , &B);

    int lenght = strlen(B);
    for(int p=0 ; p<k ; p++){
    last = B[lenght-1];
    for (i=lenght-1 ; i>0 ; i--){
        B[i]=B[i-1];
    }
    B[0] = last ;
            for(int q=0 ; q<n; q++){
        if (B[q]=='z'){
            B[q]= 'a';
        }else{
            B[q] = B[q] + 1;
        }
    }
    }
    for (j=0 ; j<n ; j++){
        printf("%c" ,B[j]);
    }
}

