#include <stdio.h>
#include <string.h>

void func(char n[10000]) {
    int m = strlen(n);
    if (m <= 2) {
        printf("%s\n", n);
        return;
    }
    char k = '\0';
    int found = 0;
    for(int i=0 ; i+1< m ; i++){
        if (n[i] == n[i+1]){
            n[i] = '\0';
            n[i+1] = '\0';
            found = 1;
        }
    }
    if (found == 0) {
        printf("%s\n", n);
        return;
    }
    char q[10000];
    int index = 0;
    for (int j = 0; j < m; j++) {
        if (n[j] != '\0') {
            q[index] = n[j];
            index++;
        }
    }
    func(q);
}

int main() {
    char str[10000];
    int q;
    scanf("%d", &q);
    scanf("%s", str);
    func(str);

    return 0;
}
