#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char names[100][21];
    int i, j;
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
    {
        scanf("%s", names[i]);
    }
    
    printf("%s to %s: yek pesh daram, pesh mindaze.\n", names[0], names[1]);
    printf("%s to %s: pesh mindaze?\n", names[1], names[0]);
    printf("%s to %s: pesh mindaze.\n", names[0], names[1]);
    
    for(i = 2; i < n; i++)
    {
        printf("%s to %s: yek pesh dare, pesh mindaze.\n", names[i-1], names[i]);
        
        for(j = i; j >= 1; j--)
        {
            printf("%s to %s: pesh mindaze?\n", names[j], names[j-1]);
        }
        
        for(j = 0; j < i; j++)
        {
            printf("%s to %s: pesh mindaze.\n", names[j], names[j+1]);
        }
    }
    
    return 0;
}
