English Summary
Maximize number of customer-house matches where house size $a_i$ satisfies $|a_i - b_j| \leq k$. Sort both arrays, use two pointers to greedily match smallest suitable house to each customer. Complexity: $O(n \log n + m \log m)$.

Algorithm:

Sort $a$ and $b$ ascending

Iterate through customers, match with smallest available house where $a \geq b-k$ and $a \leq b+k$

Greedy: if house too small ($a < b-k$), skip; if suitable, match; if too large ($a > b+k$), try next customer

Persian Summary / خلاصه فارسی
حداکثر کردن تعداد تطابق مشتری-خانه که در آن متراژ خانه $a_i$ شرط $|a_i - b_j| \leq k$ را برآورده کند. هر دو آرایه را مرتب کرده، با دو اشاره‌گر به صورت حریصانه کوچک‌ترین خانه مناسب را به هر مشتری اختصاص دهید. پیچیدگی: $O(n \log n + m \log m)$.

الگوریتم:
۱. مرتب‌سازی صعودی $a$ و $b$
۲. پیمایش مشتریان، تطابق با کوچک‌ترین خانه موجود که $a \geq b-k$ و $a \leq b+k$ باشد
۳. حریصانه: اگر خانه خیلی کوچک است ($a < b-k$)، رد شو؛ اگر مناسب است، تطابق بده؛ اگر خیلی بزرگ است ($a > b+k$)، مشتری بعدی را امتحان کن
