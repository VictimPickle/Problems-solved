# مسئله - Problem

## فارسی
شخصیت اصلی در یک **گراف بدون‌وزن و بدون‌جهت** با `n` رأس و `m` یال گیر افتاده است. او از رأس `۱` شروع می‌کند و باید به رأس `n` برسد. **کمترین تعداد رأس‌هایی** که باید از آن‌ها عبور کند (شامل رأس شروع و پایان) را پیدا کنید. اگر مسیری وجود نداشت، `IMPOSSIBLE` چاپ کنید.

## English
The main character is trapped in an **unweighted, undirected graph** with `n` vertices and `m` edges. He starts at vertex `1` and must reach vertex `n`. Find the **minimum number of vertices** he must pass through (including both start and end vertices). If no path exists, print `IMPOSSIBLE`.

---

## فرمت ورودی / Input Format
- خط اول / First line: دو عدد صحیح `n` (تعداد رأس‌ها / vertices) و `m` (تعداد یال‌ها / edges)
- `m` خط بعدی / Next `m` lines: هر خط شامل دو عدد `u` و `v` / Each contains two integers `u` and `v`, representing an edge between vertices `u` and `v`

## فرمت خروجی / Output Format
- یک عدد صحیح / A single integer (کمترین تعداد رأس‌های عبوری از `۱` به `n` / minimum vertices on a path from `1` to `n`) یا / or `IMPOSSIBLE`

## محدودیت‌ها / Constraints
- \( 1 \leq n \leq 10^5 \)
- \( 0 \leq m \leq 2 \times 10^5 \)

---

## مثال / Example

### ورودی نمونه / Sample Input
```
5 5
1 2
1 3
1 4
2 3
5 4
```

### خروجی نمونه / Sample Output
```
3
```

### توضیح / Explanation
در این مثال، کوتاه‌ترین مسیر از رأس `۱` به رأس `۵`، مسیر `۱ → ۴ → ۵` است که از **۳ رأس** (۱، ۴، ۵) عبور می‌کند.  
In this example, the shortest path from vertex `1` to vertex `5` is `1 → 4 → 5`, which passes through **3 vertices** (1, 4, 5).
