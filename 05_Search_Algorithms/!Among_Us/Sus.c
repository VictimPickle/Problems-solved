#include <stdio.h>
int main(){
    int q , b , i , j ,t ,m ,n ,o , k , w;
    scanf("%d" , &q);

    for(int i = 0 ; i<q ; i++)
    {
        scanf("%d", &b);
        scanf("%d%d%d" , &m , &n , &o);
        if (m!=n)
        {
            if(m==o)
            {
                printf("2\n");
            }
            else
            {
                printf("1\n");
            }
            for(int j = 0 ; j<b-3 ; j++)
            {
                scanf("%d",&t);

            }
        }
        if (m==n)
        {
            if(m!=o)
                printf("3\n");
            for(int j = 0 ; j<b-3 ; j++)
            {
                scanf("%d",&t);
                if (t!=m)
                    printf("%d\n",j+4);
            }
        }
    }



}
