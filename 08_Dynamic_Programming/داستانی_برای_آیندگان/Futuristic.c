#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX_VARS 26
#define MAX_STEPS 10000000

typedef struct {
    char type; // 'a' assign, 'c' cout, 'g' goto
    char var;
    char op1, op2;
    int num1, num2;
    int is_num1, is_num2;
    int goto_line;
} Instruction;

long long getValue(long long *vars, char c, int is_num, int num) {
    if (is_num) {
        return num;
    }
    return *(vars + (c - 'a'));
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    
    Instruction *instructions = (Instruction *)malloc(n * sizeof(Instruction));
    
    for (int i = 0; i < n; i++) {
        char line[100];
        fgets(line, 100, stdin);
        
        Instruction *inst = instructions + i;
        
        if (strncmp(line, "assign", 6) == 0) {
            inst->type = 'a';
            char *ptr = line + 7;
            inst->var = *ptr;
            ptr += 4;
            
            if (*ptr >= '0' && *ptr <= '9') {
                inst->is_num1 = 1;
                inst->num1 = *ptr - '0';
            } else {
                inst->is_num1 = 0;
                inst->op1 = *ptr;
            }
            ptr += 3;
            
            if (*ptr >= '0' && *ptr <= '9') {
                inst->is_num2 = 1;
                inst->num2 = *ptr - '0';
            } else {
                inst->is_num2 = 0;
                inst->op2 = *ptr;
            }
        } else if (strncmp(line, "cout", 4) == 0) {
            inst->type = 'c';
            char *ptr = line + 5;
            if (*ptr >= '0' && *ptr <= '9') {
                inst->is_num1 = 1;
                inst->num1 = *ptr - '0';
            } else {
                inst->is_num1 = 0;
                inst->op1 = *ptr;
            }
        } else if (strncmp(line, "goto", 4) == 0) {
            inst->type = 'g';
            sscanf(line + 5, "%d", &(inst->goto_line));
        }
    }
    
    long long *vars = (long long *)calloc(MAX_VARS, sizeof(long long));
    int current_line = 0;
    long long steps = 0;
    
    while (current_line < n && steps < MAX_STEPS) {
        Instruction *inst = instructions + current_line;
        
        if (inst->type == 'a') {
            long long val1 = getValue(vars, inst->op1, inst->is_num1, inst->num1);
            long long val2 = getValue(vars, inst->op2, inst->is_num2, inst->num2);
            *(vars + (inst->var - 'a')) = (val1 + val2) % MOD;
            current_line++;
        } else if (inst->type == 'c') {
            long long val = getValue(vars, inst->op1, inst->is_num1, inst->num1);
            printf("%lld\n", val % MOD);
            current_line++;
        } else if (inst->type == 'g') {
            current_line = inst->goto_line - 1;
        }
        
        steps++;
    }
    
    if (steps >= MAX_STEPS) {
        printf("-1\n");
    }
    
    free(vars);
    free(instructions);
    
    return 0;
}
