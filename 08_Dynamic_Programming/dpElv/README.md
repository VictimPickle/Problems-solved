# dpElv

## English Summary
Given an elevator with capacity $b$ and $n$ people with weights $\lbrace w_{0},w_{1},...,w_{n-1}\rbrace$ and values $\lbrace v_{0},v_{1},...,v_{n-1}\rbrace$, write a dynamic programming program to find a binary vector $x \in \lbrace 0,1 \rbrace^{n}$ such that $\sum_{i=0}^{n-1} w_{i}x_{i} \leq b$ and $\sum_{i=0}^{n-1} v_{i}x_{i}$ is maximized.

## Persian Summary / خلاصه فارسی
در این مسئله، یک برنامه‌ی برنامه‌نویسی پویا برای یافتن بردار دودویی $x \in \lbrace 0,1 \rbrace^{n}$ که شرایط $\sum_{i=0}^{n-1} w_{i}x_{i} \leq b$ و $\sum_{i=0}^{n-1} v_{i}x_{i}$ بیشینه شود، برای یک آسانسور با ظرفیت $b$ و $n$ نفر با وزن‌ها و ارزش‌های مشخص داده شده است.