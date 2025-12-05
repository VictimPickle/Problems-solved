#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int n;
int A[100005];
int B[100005];
int seated[100005];
int order[100005];
int used[100005];
long long result = 0;

int findSeat(int assigned) {
    int pos = assigned;
    while (seated[pos]) {
        pos++;
        if (pos > n) pos = 1;
    }
    return pos;
}

int checkOrder() {
    memset(seated, 0, sizeof(seated));
    for (int i = 0; i < n; i++) {
        int guest = order[i];
        int assigned = A[guest];
        int actualSeat = findSeat(assigned);
        if (actualSeat != B[guest]) {
            return 0;
        }
        seated[actualSeat] = 1;
    }
    return 1;
}

void permute(int pos) {
    if (pos == n) {
        if (checkOrder()) {
            result = (result + 1) % MOD;
        }
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = 1;
            order[pos] = i;
            permute(pos + 1);
            used[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &B[i]);
    }
    
    memset(used, 0, sizeof(used));
    permute(0);
    
    printf("%lld\n", result);
    
    return 0;
}
