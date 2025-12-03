#include<stdio.h>
int main(){
    int i , j;
    int A[4][4] , B[4][4];

    for (i=0 ; i<4 ; i++){
        for(j=0 ; j<4 ; j++){
            scanf("%d" , &A[i][j]);
        }
    }
    for (i=0 ; i<4 ; i++){
        for(j=0 ; j<4 ; j++){
            B[i][j] = 0;
        }
    }

    for (i=0 ; i<4 ; i++){
        int max = A[i][0];
        for(j=0 ; j<4 ; j++){
            if (A[i][j] > max)
                max = A[i][j];

        }
        for(j=0 ; j<4 ; j++){
            if (A[i][j] == max)
                B[i][j]++;

        }
    }

    for (i=0 ; i<4 ; i++){
        int max = A[0][i];
        for(j=0 ; j<4 ; j++){
            if (A[j][i] > max)
                max = A[j][i];
        }

        for(j=0 ; j<4 ; j++){
            if (A[j][i] == max)
                B[j][i]++;
        }
    }

    for(i=0 ; i<4 ; i++){
        for(j=0 ; j<4 ; j++){
            if (B[i][j] == 2){
                printf("%d %d\n" , i ,j);
            }
        }
    }
    /*
    // we have to select an element an check in row and columns so:
    for(int y=0 ; y<4 ; y++){
        for(int u=0 ; u<4 ; u++)
            //A[y][o]
        // I have to define one for row and another for column
            {for (int r=0 ; r<4 ; r++){
                if (A[r][u] > A[y][u]){
                    B[y][u]= 1;
                }
            }
            for (int p=0 ; p<4 ; p++){
                if (A[y][p]>A[y][u]){
                    B[y][u] = 1;
                }
            }
        }
    }
    for (i=0 ; i<4 ; i++){
        for(j=0 ; j<4 ; j++){
            if(B[i][j] == 0){
                printf("%d %d \n" , i , j);
            }
        }
    }

*/
}
