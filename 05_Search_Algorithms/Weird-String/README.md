# 11.2 - Weird String | رشته عجیب

## English

### Problem Summary

This is a **backtracking permutation problem**. You need to generate a permutation of numbers 1 to n where consecutive elements have a specific distance constraint. The goal is to find a valid "weird" sequence where each number's distance from its neighbors satisfies certain conditions.

### Key Concepts

- **Algorithm**: Backtracking + Constraint Validation
- **Complexity**: O(n! × n) where n is the sequence length  
- **Category**: Backtracking, Permutations, Constraint Satisfaction

### Problem Details

**Input:**
- An integer n (sequence length)
- Constraint rules for valid permutations

**Output:**
- A valid "weird" permutation sequence
- Or "NO SOLUTION" if impossible

### Solution Approach

1. Use backtracking to try different permutations
2. For each position, try placing each unused number
3. Check if the placement satisfies distance constraints
4. Backtrack if constraints are violated
5. Return the first valid solution found

### Example

```
Input:
n = 4

Output:
2 4 1 3
```

## فارسی

### خلاصه مسئله

این یک **مسئله جایگشت با بک‌ترکینگ** است. شما باید یک جایگشت از اعداد 1 تا n تولید کنید که عناصر متوالی دارای محدودیت فاصله خاصی باشند. هدف یافتن یک دنباله "عجیب" معتبر است که فاصله هر عدد از همسایگانش شرایط خاصی را برآورده سازد.

### مفاهیم کلیدی

- **الگوریتم**: بک‌ترکینگ + اعتبارسنجی محدودیت
- **پیچیدگی**: O(n! × n) که n طول دنباله است
- **دسته‌بندی**: بک‌ترکینگ، جایگشت، ارضای محدودیت

### جزئیات مسئله

**ورودی:**
- یک عدد صحیح n (طول دنباله)
- قوانین محدودیت برای جایگشت‌های معتبر

**خروجی:**
- یک دنباله جایگشت "عجیب" معتبر
- یا "NO SOLUTION" اگر غیرممکن باشد

### رویکرد حل

1. از بک‌ترکینگ برای امتحان جایگشت‌های مختلف استفاده کنید
2. برای هر موقعیت، قرار دادن هر عدد استفاده نشده را امتحان کنید
3. بررسی کنید آیا قرارگیری محدودیت‌های فاصله را برآورده می‌کند
4. بک‌ترک کنید اگر محدودیت‌ها نقض شوند
5. اولین راه‌حل معتبر یافت شده را برگردانید

## Algorithm Explanation

### Backtracking Approach

```cpp
bool solve(int position) {
    if (position == n) return true;
    
    for (int i = position + 1; i <= n; i++) {
        if (!used[i] && (!ans.empty() && abs(ans.back() - i) == 1)) {
            ans.push_back(i);
            used[i] = true;
            
            if (solve(next_position)) return true;
            
            ans.pop_back();
            used[i] = false;
        }
    }
    return false;
}
```

**Problem Source**: Quera - Series 11  
**Difficulty**: Medium  
**Tags**: Backtracking, Permutations, Constraint Satisfaction
