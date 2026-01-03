# 11.4 - Treasure Ship | کشتی گنج

## English

### Problem Summary
This is a classic **0/1 Knapsack Problem**. You have a ship with limited capacity and multiple treasures with different weights and values. Your goal is to maximize the total value while staying within the weight capacity.

### Key Concepts
- **Algorithm**: Dynamic Programming (0/1 Knapsack)
- **Complexity**: O(2^n) brute force, O(n × W) with DP
- **Category**: Optimization, Dynamic Programming

### Problem Details
**Input:**
- First line: n (number of treasures), W (ship capacity)
- Next n lines: weight and value of each treasure

**Output:**
- Maximum value that can be carried

### Solution Approach
1. Use dynamic programming table dp[i][w]
2. For each item, decide: take it or leave it
3. Maximize value while respecting weight constraint

### Example
```
Input:
3 50
10 60
20 100
30 120

Output:
220
```

---

## فارسی

### خلاصه مسئله
یک مسئله کلاسیک **کوله‌پشتی 0/1** است. شما یک کشتی با ظرفیت محدود و چندین گنج با وزن و ارزش متفاوت دارید. هدف شما به حداکثر رساندن ارزش کل با رعایت محدودیت وزن است.

### مفاهیم کلیدی
- **الگوریتم**: برنامه‌نویسی پویا (کوله‌پشتی 0/1)
- **پیچیدگی**: O(2^n) روش ساده، O(n × W) با برنامه‌نویسی پویا
- **دسته‌بندی**: بهینه‌سازی، برنامه‌نویسی پویا

### جزئیات مسئله
**ورودی:**
- خط اول: n (تعداد گنج‌ها)، W (ظرفیت کشتی)
- n خط بعدی: وزن و ارزش هر گنج

**خروجی:**
- بیشترین ارزشی که می‌توان حمل کرد

### رویکرد حل
1. استفاده از جدول برنامه‌نویسی پویا dp[i][w]
2. برای هر آیتم تصمیم بگیرید: آن را بردارید یا رها کنید
3. ارزش را با رعایت محدودیت وزن به حداکثر برسانید

---

## Algorithm Explanation

### Dynamic Programming Approach
```
dp[i][w] = maximum value using first i items with weight limit w

Recurrence:
if weight[i] > w:
    dp[i][w] = dp[i-1][w]  // can't take item
else:
    dp[i][w] = max(
        dp[i-1][w],                    // don't take
        dp[i-1][w-weight[i]] + value[i] // take it
    )
```

---

**Problem Source**: Quera - Series 11
**Difficulty**: Medium
**Tags**: Dynamic Programming, Knapsack, Optimization
