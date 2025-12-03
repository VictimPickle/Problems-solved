#include<stdio.h>
void Hanoi(int n , char a , char b , char c){
    if(n==1)
    printf("Disk %d moved from %c to %c \n" , n , a , c);
    else{
        Hanoi(n-1 , a ,c ,b);
        printf("Disk %d moved from %c to %c \n" , n , a, c);
        Hanoi(n-1 , b , a, c);
    }
}
int main() {
    int n;
    scanf("%d", &n);

    Hanoi(n, 'A', 'C', 'B');

    return 0;
}