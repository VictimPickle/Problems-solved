#include <stdio.h>
int main(){
int h,m,s,k,second,s2,m2,h2,h3,m3;
scanf("%d %d %d",&h,&m,&s);
scanf("%d", &k);
second = h*3600 + m*60 + s + k;
s2 = second%60;
m2 = (second-s2)/60;
m3 = m2%60;
h2 = (second-s2-60*m3)/3600;
h3 = h2%24;
printf("%d %d %d", h3 , m3 , s2);
return 0 ;

}
