#include <stdio.h>
int main()
{
    int x;
    char c ='a';
    scanf("%d", &x);
    if(x % 2 == 0){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < (x/2); j++){
                if(j %2 == 0){
                    printf("%c%c", c, c);
                }else
                printf("%c%c", c+1, c+1);
            }
            c +=2;
            printf("\n");
        }

        for(int i =0; i < 2; i++){
            printf("x");
            for(int j = 0; j < (x/2 - 1); j++){
                if(j %2 == 0){
                    printf("%c%c", c, c);
                }
                else{
                    printf("%c%c", c+1, c+1);

                }
            }
            c +=2;
            printf("y");
            printf("\n");
        }
    }
    if(x % 2 == 1){
        for(int i = 0; i < 2; i++){
            printf("x");
            for(int j = 0; j < (x/2); j++){
                if(j %2 == 0){
                    printf("%c%c", c, c);
                }
                else
                printf("%c%c", c+1, c+1);
            }
            c +=2;
            printf("\n");
        }

        for(int i =0; i < 2; i++){
            for(int j = 0; j < (x/2); j++){
                if(j %2 == 0){
                    printf("%c%c", c, c);
                }
                else{printf("%c%c", c+1, c+1);
                }
            }
            c +=2;
            printf("y");
            printf("\n");
        }
    }
    return 0;
}
