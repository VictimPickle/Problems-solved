# 📚 Problem Description

In this problem, you are dealing with a game consisting of **n planets** connected to each other by **m teleporters**. Two planets **a** and **b** belong to the same kingdom precisely when you can reach **b** from **a** and you can reach **a** from **b**.

Your task is to determine which kingdom each planet belongs to.

## 🎯 Input/Output Format

### Input

* First line: Two integers **n** and **m**, representing the number of planets and the number of teleporters, respectively.
* Planets are numbered from **1** to **n**.
* Next **m** lines: Each contains two integers **a** and **b**, indicating that you can travel from planet **a** to planet **b**.

**Constraints:**
* 1 ≤ n ≤ 10⁵
* 1 ≤ m ≤ 2×10⁵  
* 1 ≤ a, b ≤ n

### Output

First, print an integer **k** indicating the number of kingdoms.

Then, for each planet, print a label between **1** and **k** representing the kingdom of that planet.

Any valid answer is accepted.

### 📊 Examples

**Example 1**

```
Input:
5 6
1 2
2 3
3 1
3 4
4 5
5 4

Output:
2
1 1 1 2 2
```

## 💡 Algorithm Explanation

This problem requires finding **Strongly Connected Components (SCCs)** in a directed graph, which can be solved using **Tarjan's Algorithm**.

### Approach:

1. **Depth-First Search (DFS) based traversal**: Tarjan's algorithm uses a single DFS pass to identify all SCCs
2. **Track two values for each node**:
   - `index`: Discovery time of the node in DFS
   - `lowlink`: Lowest index reachable from this node
3. **Use a stack**: Keep track of nodes in the current SCC being explored
4. **Identify SCC roots**: When `lowlink[v] == index[v]`, node v is the root of an SCC
5. **Pop the stack**: All nodes above v in the stack form one SCC

### Key Concepts:

* **Strongly Connected Components**: Maximal sets of vertices where every vertex is reachable from every other vertex in the set
* **DFS with backtracking**: Efficiently explores the graph while identifying cycles
* **Stack management**: Maintains nodes in current exploration path

### Time Complexity:

* **Overall**: O(V + E) where V is the number of planets and E is the number of teleporters
* Single DFS traversal with O(1) operations per node and edge

### Space Complexity:

* O(V + E) for adjacency list representation
* O(V) for index, lowlink, and stack arrays

---

**Problem Source**: [Quera - طراحی و تحلیل الگوریتم‌ها - سری ۱۰](https://quera.org/course/assignments/93579/problems/316239)

**Category**: Graph Algorithms - Strongly Connected Components

**Difficulty**: Medium
