# Sambasiva - Graph Connectivity Problem

## Problem Summary

### English

**Problem:** Determine if a directed graph is strongly connected (i.e., whether there exists a directed path between every pair of vertices).

**Context:** Hashem wants to prove to his friend Sambasiva that he can handle any task independently. He has a directed graph with \(n\) vertices and wants to check if every vertex is reachable from every other vertex by following directed edges. The challenge explicitly requires solving this without using Kosaraju's algorithm.

**Constraints:**
- \(1 \leq n \leq 10^5\) (number of vertices)
- \(1 \leq m \leq 2 \times 10^5\) (number of edges)
- \(1 \leq u, v \leq n\), \(u \neq v\) (directed edge from \(u\) to \(v\))

**Time Limit:** 1 second  
**Memory Limit:** 256 MB

**Input Format:**
- First line: two integers \(n\) and \(m\)
- Next \(m\) lines: two integers \(u\) and \(v\) representing a directed edge from vertex \(u\) to vertex \(v\)

**Output Format:**
- Print `YES` if the graph is strongly connected (every vertex is reachable from every other vertex)
- Print `NO` otherwise

**Examples:**

Example 1:
```
Input:
4 5
1 2
2 3
3 1
1 4
3 4

Output: NO
```

Example 2:
```
Input:
3 3
1 2
2 3
3 1

Output: YES
```

---

### Persian (فارسی)

**مسئله:** تعیین اینکه آیا یک گراف جهت‌دار، قویاً همبند است یا خیر (یعنی آیا بین هر دو رأس مسیری جهت‌دار وجود دارد).

**داستان مسئله:** روابط هاشم و دوستش سامباسیوا دچار مشکل شده است. هاشم می‌خواهد ثابت کند که به‌تنهایی از پس هر کاری برمی‌آید. او یک گراف جهت‌دار با \(n\) رأس دارد و می‌خواهد بداند آیا از هر رأسی می‌توان به هر رأس دیگری با دنبال کردن یال‌های جهت‌دار رسید یا خیر. نکته مهم: حل این مسئله بدون استفاده از الگوریتم Kosaraju مورد نیاز است.

**محدودیت‌ها:**
- \(1 \leq n \leq 10^5\) (تعداد رئوس)
- \(1 \leq m \leq 2 \times 10^5\) (تعداد یال‌ها)
- \(1 \leq u, v \leq n\)، \(u \neq v\) (یال جهت‌دار از \(u\) به \(v\))

**محدودیت زمان:** ۱ ثانیه  
**محدودیت حافظه:** ۲۵۶ مگابایت

**فرمت ورودی:**
- خط اول: دو عدد صحیح \(n\) و \(m\)
- \(m\) خط بعدی: دو عدد صحیح \(u\) و \(v\) که نشان‌دهنده یال جهت‌دار از رأس \(u\) به رأس \(v\) است

**فرمت خروجی:**
- اگر گراف قویاً همبند است (از هر رأسی به هر رأس دیگری می‌توان رسید) `YES` چاپ کنید
- در غیر این صورت `NO` چاپ کنید

**مثال‌ها:**

مثال ۱:
```
ورودی:
4 5
1 2
2 3
3 1
1 4
3 4

خروجی: NO
```

مثال ۲:
```
ورودی:
3 3
1 2
2 3
3 1

خروجی: YES
```

---

- Since Kosaraju's algorithm is explicitly forbidden, consider using Tarjan's SCC algorithm or a two-pass DFS approach

**Source:** Quera - Algorithm Design and Analysis Course
