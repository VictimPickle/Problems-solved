# Magic Collection - جمع‌آوری ماژیک

## Problem Description

### English
Character 3 is exploring the university. The classrooms can be represented as a directed graph with `n` vertices and `m` edges. In classroom `i`, there are `c[i]` magic items.

Character 3 wants to start their journey from any classroom and traverse through several edges. During the journey, whenever they reach a classroom, they collect all the magic items in that classroom.

Since Character 3 loves collecting magic items, they want to find the maximum number of magic items they can collect using this method.

Note that Character 3 can visit a classroom multiple times; the only restriction is that they can only traverse edges in the given direction.

### Persian (فارسی)
شخصیت اصلی ۳ مشغول گشت‌وگذار در دانشکده است. کلاس‌های دانشکده را می‌توان به‌صورت یک گراف جهت‌دار با n رأس و m یال نمایش داد. در کلاس i‌ام، تعداد c[i] ماژیک قرار دارد.

شخصیت اصلی ۳ می‌خواهد گشت‌وگذار خود را از یک کلاس دل‌خواه شروع کند و پس از طی‌کردن تعدادی یال، آن را به پایان برساند. در طول گشت‌وگذار، هر بار که او به یک کلاس برسد، تمام ماژیک‌های آن کلاس را برمی‌دارد.

از آن‌جا که شخصیت اصلی ۳ بسیار علاقه‌مند به جمع‌آوری ماژیک‌ها است، از شما می‌خواهد بیشترین تعداد ماژیکی را که می‌تواند به این روش جمع‌آوری کند، پیدا کنید.

## Constraints
- 1 ≤ n ≤ 10^5
- 1 ≤ m ≤ 2×10^5
- 1 ≤ c[i] ≤ 10^9
- Time Limit: 1 second
- Memory Limit: 256 MB

## Input Format
- First line: Two integers `n` and `m` (number of classrooms and edges)
- Second line: `n` integers `c[1], c[2], ..., c[n]` (magic items in each classroom)
- Next `m` lines: Two integers `u` and `v` representing a directed edge from classroom `u` to classroom `v`

## Output Format
Print one integer — the maximum number of magic items Character 3 can collect.

## Sample Input
```
4 4
4 5 2 7
1 2
2 1
1 3
2 4
```

## Sample Output
```
16
```

## Solution Approach

This problem uses **Strongly Connected Components (SCC)** and **Dynamic Programming on DAG**:

### Algorithm Steps:

1. **Find SCCs using Kosaraju's Algorithm**:
   - First DFS on original graph to get finish times
   - Second DFS on transpose graph to identify SCCs
   - Nodes in the same SCC can all be visited in one path

2. **Build a DAG of SCCs**:
   - Contract each SCC into a single node
   - Create edges between different SCCs
   - Calculate the sum of magic items in each SCC

3. **DP on DAG**:
   - For each SCC node, calculate maximum magic items obtainable
   - `dp[v] = sum[v] + max(dp[child])` for all children
   - Answer is the maximum dp value among all SCC nodes

### Complexity
- Time: O(n + m)
- Space: O(n + m)

## Key Concepts
- Strongly Connected Components (SCC)
- Kosaraju's Algorithm
- Dynamic Programming on DAG
- Graph Traversal (DFS)
- Topological Ordering

## Source
Problem from [Quera.org](https://quera.org) - Algorithm Design Course

## Tags
`Graph Algorithms` `SCC` `Dynamic Programming` `DFS` `DAG` `Competitive Programming`
