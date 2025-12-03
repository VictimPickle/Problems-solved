    #include <stdio.h>
    int main(){
        int i , j , n , Truth = 1 , m , k ,o , q , w , teadad;
      scanf("%d",&n);
      int A[n+1][n+1];
      for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
          scanf("%d",&A[i][j]);
      }
      for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
                k = A[i][j];
                m=i;
                o=j;
                for (int p=m+1;p<=n;p++){
                    if (A[p][o] == k)
                        Truth = 0;
                        break;
                }
                for (int y=o+1 ; y<=n ; y++){
                    if(A[m][y] == k){
                        Truth = 0;
                        break;
                    }
                }
        }
      }

                // Checking the small squares

        int s,d,f,g,h,l, count ,r,t,u;
        // r , t are i and j s of squares
        s = sqrt(n);
        for (t=1 ; t<=n ; t +=s){
            for(r=1 ; r<=n ; r +=s){
                 // now that squares are done we analyze the squares
                    for(h = t ; h < t+s ; h++){
                        for(g = r ; g < r+s; g++){
                                count =0;
                            int yo = A[g][h];
                                for(int po=t ; po<t+s ; po++){
                                    for(int pq=r ; pq<r+s ; pq++){
                                        if (A[po][pq] == yo){
                                            count++;
                                        }
                                    }
                                }
                                if (count !=1)
                                    Truth = 0;
                        }
                    }

            }

        }






            // until here
        if (Truth == 0){
            printf("No");
        }
        else{
        printf("Yes");
        }
        return 0;

    }
