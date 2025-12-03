#include <stdio.h>

void print(int q , int n, int increase){
    if (q < 2){
        increase = 1;
        printf("1 ");
    }
    else if (q > n) {
        return;
    }
    printf("%d ", q);
    if (increase == 0) {
        print(q - 1 , n, 0);
    } else {
        print(q + 1 , n, 1);
    }
}

int main(){
    int n;
    scanf("%d" , &n);
    print(n , n, 0);
}
