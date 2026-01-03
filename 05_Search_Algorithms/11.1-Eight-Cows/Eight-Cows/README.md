# 11.1 - Eight Cows | هشت گاو

## English

### Problem Summary
This is a **permutation and constraint satisfaction problem**. You have 8 cows that need to be arranged in a specific pattern, where each cow has certain requirements about its neighbors. The goal is to find a valid arrangement that satisfies all constraints.

### Key Concepts
- **Algorithm**: Permutation Generation + Constraint Validation
- **Complexity**: O(8! × n) where n is number of constraints
- **Category**: Backtracking, Constraint Satisfaction

### Problem Details
**Input:**
- Constraints describing which cows can be neighbors
- Number of cows: 8

**Output:**
- A valid arrangement of the 8 cows
- Or "No solution" if impossible

### Solution Approach
1. Generate all permutations of 8 cows (8! = 40,320)
2. For each permutation, check if all constraints are satisfied
3. Return the first valid arrangement found
4. Optimization: Use backtracking to prune invalid branches early

### Example
```
Input:
Cow constraints...

Output:
Arrangement: 1 3 5 7 2 4 6 8
```

---

## فارسی

### خلاصه مسئله
این یک **مسئله جایگشت و ارضای محدودیت** است. شما 8 گاو دارید که باید به گونه‌ای خاص چیده شوند که هر گاو الزامات خاصی درباره همسایگانش دارد. هدف یافتن یک آرایش معتبر است که همه محدودیت‌ها را برآورده سازد.

### مفاهیم کلیدی
- **الگوریتم**: تولید جایگشت + اعتبارسنجی محدودیت
- **پیچیدگی**: O(8! × n) که n تعداد محدودیت‌هاست
- **دسته‌بندی**: بک‌ترکینگ، ارضای محدودیت

### جزئیات مسئله
**ورودی:**
- محدودیت‌هایی که توصیف می‌کنند کدام گاوها می‌توانند همسایه باشند
- تعداد گاوها: 8

**خروجی:**
- یک آرایش معتبر از 8 گاو
- یا "بدون جواب" اگر غیرممکن باشد

### رویکرد حل
1. تولید همه جایگشت‌های 8 گاو (8! = 40,320)
2. برای هر جایگشت، بررسی کنید آیا همه محدودیت‌ها برآورده می‌شوند
3. اولین آرایش معتبر را برگردانید
4. بهینه‌سازی: از بک‌ترکینگ برای هرس زودهنگام شاخه‌های نامعتبر استفاده کنید

---

## Algorithm Explanation

### Backtracking Approach
```cpp
bool isValid(vector<int>& arrangement, constraints) {
    // Check all constraint rules
    for (each constraint) {
        if (violated) return false;
    }
    return true;
}

void solve(vector<int>& current, int position) {
    if (position == 8) {
        if (isValid(current)) {
            print(current);
            return;
        }
    }
    
    for (int cow = 1; cow <= 8; cow++) {
        if (!used[cow]) {
            current[position] = cow;
            used[cow] = true;
            solve(current, position + 1);
            used[cow] = false;
        }
    }
}
```

---

**Problem Source**: Quera - Series 11
**Difficulty**: Medium
**Tags**: Backtracking, Permutations, Constraint Satisfaction
