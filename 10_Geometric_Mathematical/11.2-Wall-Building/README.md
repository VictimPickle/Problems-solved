# 11.2 - Wall Building | ساخت دیوار

## English

### Problem Summary
This is a **cost optimization problem**. You need to build a wall with specific dimensions while minimizing the total cost. The wall consists of blocks with different costs, and you must find the most economical way to construct it while satisfying all constraints.

### Key Concepts
- **Algorithm**: Optimization, Mathematical Calculation
- **Complexity**: O(n × m) where n and m are dimensions
- **Category**: Optimization, Geometry, Mathematics

### Problem Details
**Input:**
- Wall dimensions (height, width)
- Block types with costs
- Construction constraints

**Output:**
- Minimum cost to build the wall
- Optimal block arrangement

### Solution Approach
1. Analyze block sizes and costs
2. Calculate cost per unit area for each block type
3. Apply greedy strategy or dynamic programming
4. Ensure all constraints are satisfied
5. Return minimum total cost

### Example
```
Input:
Wall: 10m × 5m
Block A: 1m × 1m, Cost: 5
Block B: 2m × 1m, Cost: 8

Output:
Minimum Cost: 200
```

---

## فارسی

### خلاصه مسئله
این یک **مسئله بهینه‌سازی هزینه** است. شما باید دیواری با ابعاد مشخص بسازید و هزینه کل را کمینه کنید. دیوار از آجرهایی با هزینه‌های مختلف تشکیل شده و باید اقتصادی‌ترین روش ساخت را با رعایت همه محدودیت‌ها پیدا کنید.

### مفاهیم کلیدی
- **الگوریتم**: بهینه‌سازی، محاسبات ریاضی
- **پیچیدگی**: O(n × m)
- **دسته‌بندی**: بهینه‌سازی، هندسه، ریاضیات

### جزئیات مسئله
**ورودی:**
- ابعاد دیوار (ارتفاع، عرض)
- انواع آجر با هزینه‌ها
- محدودیت‌های ساخت

**خروجی:**
- حداقل هزینه ساخت دیوار
- آرایش بهینه آجرها

### رویکرد حل
1. تحلیل ابعاد و هزینه‌های آجرها
2. محاسبه هزینه به ازای واحد سطح
3. استفاده از رویکرد حریصانه یا برنامه‌نویسی پویا
4. اطمینان از برآورده شدن همه محدودیت‌ها
5. بازگشت حداقل هزینه کل

---

## Algorithm Explanation

### Optimization Approach
```
1. Calculate cost efficiency for each block type
2. Sort blocks by cost per unit area
3. Use most efficient blocks first
4. Handle remaining space with next best option
5. Return total minimum cost
```

---

**Problem Source**: Quera - Series 11  
**Difficulty**: Medium  
**Tags**: Optimization, Greedy, Mathematics, Geometry
