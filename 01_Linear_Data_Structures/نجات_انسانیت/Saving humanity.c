#include <stdio.h>
#include <string.h>
int main(){
    int j=0, i;
    int len=0;
    char A[700];
    scanf("%s" , A);
    len = strlen(A)-1;

    for (i=0;i<=len/2;i++){
        if (A[0+i]!=A[len-i]) {
                j++;
    }
    }
    if (j>1) {
        printf("No");
    }else{
        printf("Yes");
    }
    return 0;
}
