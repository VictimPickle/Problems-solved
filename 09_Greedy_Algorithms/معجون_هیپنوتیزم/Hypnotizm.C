#include <stdio.h>

int main() {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    
    long long min_potions, max_potions;
    
    long long base_size = n / m;
    long long remainder = n % m;
    
    long long larger_groups = remainder;
    long long smaller_groups = m - remainder;
    
    min_potions = larger_groups * (base_size + 1) * base_size / 2 + 
                  smaller_groups * base_size * (base_size - 1) / 2;
    
    long long large_group_size = n - m + 1;
    max_potions = large_group_size * (large_group_size - 1) / 2;
    
    printf("%lld %lld\n", min_potions, max_potions);
    
    return 0;
}
