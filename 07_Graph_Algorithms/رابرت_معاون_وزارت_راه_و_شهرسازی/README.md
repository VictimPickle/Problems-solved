# 📖 Problem Description
Marcus and Robert have been assigned to connect a network of cities. In this land, there are n cities, and certain roads with specified costs can be constructed between some of them.

Their goal is to connect all cities so that every city is reachable from every other city, while minimizing the total construction cost.

Robert said: "We need to build just enough roads to connect all cities—no more."

Marcus added: "And of course, we must choose the cheapest possible combination of roads."

If it is impossible to connect all cities, Marcus regretfully says: "This task is impossible."

Your task is to help Marcus and Robert calculate the minimum cost required to connect all cities, or determine if such a connection is not feasible.

# 🎯 Input/Output Format
## Input
- First line: Two natural numbers `n` and `m` separated by a space, representing the number of cities and the number of roads, respectively.
- Next `m` lines: Each contains three numbers `a`, `b`, `c`, indicating that a road can be built between cities `a` and `b` with cost `c`.

**Constraints:**
- 1 ≤ n ≤ 10⁵
- 1 ≤ m ≤ 2×10⁵
- 1 ≤ a, b ≤ n
- 1 ≤ c ≤ 10⁹

## Output
Your program's output should consist of a single line containing the minimum cost required to connect all cities. If this is not possible, output "IMPOSSIBLE".

### 📊 Examples
**Example 1**
```
Input:
5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4

Output:
14
```

# 💡 Algorithm Explanation
This problem is a classic **Minimum Spanning Tree (MST)** problem, solved using **Kruskal's Algorithm** with **Union-Find (Disjoint Set Union)** data structure.

## Approach:
1. **Sort all edges** by their cost in ascending order
2. **Initialize Union-Find** structure with each city as its own component
3. **Iterate through sorted edges**:
   - For each edge, check if it connects two different components
   - If yes, add the edge to MST and unite the components
   - If no, skip the edge (it would create a cycle)
4. **Check connectivity**: If we added exactly `n-1` edges, all cities are connected

## Key Concepts:
- **Union-Find with Path Compression**: Efficiently manages disjoint sets
- **Greedy Selection**: Always pick the cheapest available edge that doesn't form a cycle
- **MST Property**: A tree connecting n nodes requires exactly n-1 edges

## Time Complexity:
- Sorting edges: O(m log m)
- Union-Find operations: O(m α(n)) where α is the inverse Ackermann function (nearly constant)
- **Overall**: O(m log m)

## Space Complexity:
- O(n + m) for storing parent array and edge list

---

**Problem Source**: [Quera - طراحی و تحلیل الگوریتم‌ها](https://quera.org/course/assignments/93579/problems/316238)

**Category**: Graph Algorithms - Minimum Spanning Tree

**Difficulty**: Medium