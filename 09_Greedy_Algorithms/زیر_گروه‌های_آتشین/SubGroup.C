#include <stdio.h>
#include <string.h>

void generateSubsets(char* str, char* current, int index, int currentLen, int n) {
    if (index == n) {
        if (currentLen > 0) {
            current[currentLen] = '\0';
            printf("%s\n", current);
        }
        return;
    }
    
    current[currentLen] = str[index];
    generateSubsets(str, current, index + 1, currentLen + 1, n);
    
    generateSubsets(str, current, index + 1, currentLen, n);
}

int main() {
    int n;
    char str[11];
    char current[11];
    
    scanf("%d", &n);
    scanf("%s", str);
    
    generateSubsets(str, current, 0, 0, n);
    
    return 0;
}
