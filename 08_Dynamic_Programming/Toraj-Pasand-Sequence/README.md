# Toraj-Pasand Sequence (دنباله تورج پسند)

## Problem Description (English)

After Touk's success in winning Popak's heart, he faces a new challenge. To propose to Popak, he must solve a difficult problem set by her father, Mr. Toraj.

Mr. Toraj considers a sequence A₁, A₂, ..., Aₖ of integers as a "good sequence" if the following conditions hold:

- For every 1 ≤ i ≤ k: 0 ≤ aᵢ ≤ 2·d
- For every 2 ≤ i ≤ k: |aᵢ - aᵢ₋₁| ≤ d

Mr. Toraj has determined the values d and k for Touk. Now, Touk must find the number of good sequences modulo 10⁹ + 7 to be able to propose to Popak.

## توضیحات مسئله (فارسی)

پس از موفقیت توک در به دست آوردن دل پوپک، او با چالشی جدید روبرو شده است. او برای اینکه بتواند به خواستگاری پوپک برود باید مسئله سختی که پدر پوپک - همان آقا تورج - برای توک تعیین کرده است را حل کند.

آقا تورج دنباله A₁, A₂, ..., Aₖ از اعداد حسابی را دنباله‌ای خوب می‌داند اگر شرایط زیر برقرار باشد:

- برای هر ۱ ≤ i ≤ k: ۰ ≤ aᵢ ≤ ۲ · d
- برای هر ۲ ≤ i ≤ k: |aᵢ - aᵢ₋₁| ≤ d

آقا تورج مقادیر d و k را برای توک معین کرده است. اکنون توک باید باقی‌مانده تعداد دنباله‌های خوب را بر 10⁹ + 7 بیابد تا بتواند به خواستگاری پوپک برود.

## Constraints

- Time Limit: 4 seconds
- Memory Limit: 256 MB
- 0 ≤ d ≤ 50
- 1 ≤ k ≤ 10¹⁸

## Input Format

The only line of input contains two integers d and k.

## Output Format

Print one integer — the number of good sequences modulo 10⁹ + 7.

## Sample Examples

### Sample Input 1
```
2 2
```

### Sample Output 1
```
11
```

### Sample Input 2
```
9 1
```

### Sample Output 2
```
8119
```

## Solution Approach

This problem can be solved using **Matrix Exponentiation**:

1. **Matrix Modeling**: Build a transition matrix T where T[i][j] = 1 if |i - j| ≤ d (i.e., it's possible to transition from state i to state j).

2. **Matrix Power Calculation**: Using Fast Exponentiation algorithm, compute T^(k-1).

3. **Sum All Elements**: The final answer is the sum of all elements in matrix T^(k-1) modulo 10⁹ + 7.

### Time Complexity
- O(n³ log k) where n = 2d + 1
- Given the constraint d ≤ 50, this complexity is acceptable.

## Tags
`DP` `Matrix-Exponentiation` `Math` `Combinatorics` `Algorithm`
