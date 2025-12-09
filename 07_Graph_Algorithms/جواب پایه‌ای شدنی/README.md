# فارسی
شخصیت اصلی در یک گراف بدون‌وزن و بدون‌جهت با $n$ رأس و $m$ یال گیر افتاده است. او از رأس $1$ شروع می‌کند و می‌خواهد به رأس $n$ برسد. کمترین تعداد رأس‌هایی که باید از آنها عبور کند (شامل رأس شروع و پایان) را پیدا کنید. اگر مسیری وجود نداشت، خروجی را IMPOSSIBLE چاپ کنید.

ورودی:

خط اول: دو عدد $n$ (تعداد رأس‌ها) و $m$ (تعداد یال‌ها)

$m$ خط بعدی: هر خط شامل دو عدد $u$ و $v$، نشان‌دهنده‌ی یک یال بین رأس‌های $u$ و $v$

خروجی:

یک عدد صحیح (کمترین تعداد رأس‌های عبوری از $1$ به $n$) یا IMPOSSIBLE

محدودیت‌ها:

$1 \leq n \leq 10^5$

$0 \leq m \leq 2 \times 10^5$

3 English
The main character is stuck in an unweighted, undirected graph with $n$ vertices and $m$ edges. He starts at vertex $1$ and needs to reach vertex $n$. Find the minimum number of vertices he must pass through (including start and end vertices). If no path exists, print IMPOSSIBLE.

Input:

First line: Two integers $n$ (number of vertices) and $m$ (number of edges)

Next $m$ lines: Each line contains two integers $u$ and $v$, indicating an edge between vertices $u$ and $v$

Output:

A single integer (minimum number of vertices on a path from $1$ to $n$) or IMPOSSIBLE

Constraints:

$1 \leq n \leq 10^5$

$0 \leq m \leq 2 \times 10^5$

$1 \leq n \leq 10^5$

$0 \leq m \leq 2 \times 10^5$


## Input
```
5 5
1 2
1 3
1 4
2 3
5 4
```
## Output
```
3
```
