#include <stdio.h> 
#include <string.h> 
void compressor(char string[]) 
{ 
    int length = strlen(string); 
    for (int i = 0; i < length; i++)  
    { 
        int count = 1; 
        while (i+1<length && string[i] == string[i + 1])  
        { 
            count++; 
            i++; 
        } 
        printf("%c", string[i]); 
        if (count > 1)  
        { 
            printf("%d", count); 
        } 
    } 
    printf("\n"); 
} 
 
void expandor(char stg[]) 
{ 
    int length = strlen(stg); 
 
    for (int i = 0; i < length; i++)  
    { 
        char help = stg[i]; 
        int count = 0; 
        char r; 
        int flag = 0; 
 
        if(help <= 'z' && help >= 'a') 
        { 
            r = help; 
        } 
        else if(help >= 'A' && help <= 'Z') 
        { 
            r=help; 
        } 
 
        while (i < length && help >= '0' && help <= '9') 
        { 
            count = count * 10 + (help - '0'); 
            i++; 
            flag = 1; 
            help = stg[i]; 
        } 
        if( flag == 1 ) 
        { 
            i -= 1; 
        } 
        if(count==0){
        printf("%c", r); 
        }
        else{
        for (int j = 0; j < count-1; j++)  
        { 
            printf("%c", r); 
        } 
        }
    } 
    printf("\n"); 
 
 
} 
int main(){ 
    int n , m , o; 
    char A[10000] , B[10000]; 
    scanf("%d" , &n); 
    for (int i = 0; i < n; i++){ 
        scanf("%d", &m); 
        scanf("%s", A); 
        if (m==1){ 
            compressor(A); 
        } 
        else if(m==2){ 
            expandor(A); 
        } 
 
    } 
}