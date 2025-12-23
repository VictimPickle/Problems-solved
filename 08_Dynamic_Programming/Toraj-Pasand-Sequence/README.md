# دنباله تورج پسند (Toraj-Pasand Sequence# Toraj-Pasand Sequence

## Problem Description

After Touk's success in winning Popak's heart, he faces a new challenge. To propose to Popak, he must solve a difficult problem set by her father, Mr. Toraj.

Mr. Toraj considers a sequence A₁, A₂, ..., Aₖ of integers as a "good sequence" if the following conditions hold:

- For every 1 ≤ i ≤ k: 0 ≤ aᵢ ≤ 2·d
- For every 2 ≤ i ≤ k: |aᵢ - aᵢ₋₁| ≤ d

Mr. Toraj has determined the values d and k for Touk. Now, Touk must find the number of good sequences modulo 10⁹ + 7 to be able to propose to Popak.

## Constraints

- Time Limit: 4 seconds
- Memory Limit: 256 MB
- 0 ≤ d ≤ 50
- 1 ≤ k ≤ 10¹⁸

## Input Format

The only line of input contains two integers k and d.

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

### Sample Input 3
```
10 1
```

### Sample Output 3
```
[Expected output not provided]
```

## Solution Approach

This problem can be solved using **Matrix Exponentiation**:

1. **Matrix Modeling**: Build a transition matrix T where T[i][j] = 1 if |i - j| ≤ d (i.e., it's possible to transition from state i to state j).

2. **Matrix Power Calculation**: Using Fast Exponentiation algorithm, compute T^(k-1).

3. **Sum All Elements**: The final answer is the sum of all elements in matrix T^(k-1) modulo 10⁹ + 7.

### Time Complexity
- O(n³ log k) where n = 2d + 1
- Given the constraint d ≤ 50, this complexity is acceptable.

## Problem Link
[View problem on Quera](https://quera.org/course/assignments/93579/)

## Tags
`DP` `Matrix-Exponentiation` `Math` `Combinatorics` `Algorithm`

---

)

## توضیحات مسئله

پس از موفقیت توک در به دست آوردن دل پوپک، او با چالشی جدید روبرو شده است. او برای اینکه بتواند به خواستگاری پوپک برود باید مساله سختی که پدر پوپک - همان آقا تورج - برای توک تعیین کرده است را حل کند.

آقا تورج دنباله A₁, A₂, ..., Aₖ از اعداد حسابی را دنباله‌ای خوب می‌داند اگر شرایط زیر برقرار باشد:

- برای هر ۱ ≤ i ≤ k: ۰ ≤ aᵢ ≤ ۲ · d
- برای هر ۲ ≤ i ≤ k: |aᵢ - aᵢ₋₁| ≤ d

آقا تورج مقادیر d و k را برای توک معین کرده است. اکنون توک باید باقی‌مانده تعداد دنباله‌های خوب را بر 10⁹ + 7 بیابد تا بتواند به خواستگاری پوپک برود.

## محدودیت‌ها

- محدودیت زمان: ۴ ثانیه
- محدودیت حافظه: ۲۵۶ مگابایت
- 0 ≤ d ≤ 50
- 1 ≤ k ≤ 10¹⁸

## ورودی

در تنها خط ورودی به ترتیب دو عدد k و d آمده است.

## خروجی

در تنها خط خروجی باقی‌مانده تعداد دنباله‌های خوب بر 10⁹ + 7 را چاپ کنید.

## مثال‌ها

### ورودی نمونه ۱
```
2 2
```

### خروجی نمونه ۱
```
11
```

### ورودی نمونه ۲
```
9 1
```

### خروجی نمونه ۲
```
8119
```

### ورودی نمونه ۳
```
10 1
```

### خروجی نمونه ۳
```
[Expected output not provided]
```

## رویکرد حل

این مسئله با استفاده از **توان‌رسانی ماتریس (Matrix Exponentiation)** قابل حل است:

1. **مدل‌سازی با ماتریس**: یک ماتریس انتقال T ساخته می‌شود که T[i][j] = 1 اگر |i - j| ≤ d باشد (یعنی می‌توان از حالت i به حالت j رفت).

2. **محاسبه توان ماتریس**: با استفاده از الگوریتم توان‌رسانی سریع (Fast Exponentiation)، ماتریس T را به توان k-1 می‌رسانیم.

3. **جمع کل عناصر**: پاسخ نهایی مجموع تمام عناصر ماتریس T^(k-1) است که به ماژول 10⁹ + 7 محاسبه می‌شود.

### پیچیدگی زمانی
- O(n³ log k) که n = 2d + 1
- با توجه به محدودیت d ≤ 50، این پیچیدگی قابل قبول است.

## لینک مسئله

[مشاهده مسئله در Quera](https://quera.org/course/assignments/93579/)

## تگ‌ها

`DP` `Matrix-Exponentiation` `Math` `Combinatorics` `Algorithm`
