# Competitive Programming Solutions

A comprehensive collection of categorized algorithm and data structure solutions organized by topic and difficulty level. All solutions are implemented in C++ with optimized approaches, complexity analysis, and detailed comments.

## 📋 Repository Structure

Problems are organized into 10 major categories:

| Category | Focus Area | Algorithms/Topics |
|---|---|---|
| **01_Linear_Data_Structures** | Sequential storage | Arrays, Linked Lists, Stacks, Queues, Deques |
| **02_Tree_Structures** | Hierarchical data | Binary Trees, BST, AVL, Segment Trees, Tries |
| **03_Graph_Structures** | Network representation | Adjacency Matrix, List, DAG, Bipartite Graphs |
| **04_Advanced_Data_Structures** | Complex structures | Heaps, Hash Tables, Union-Find, Fenwick Trees |
| **05_Search_Algorithms** | Finding elements | Binary Search, Ternary Search, DFS, BFS |
| **06_Sorting_Algorithms** | Ordering elements | Quicksort, Mergesort, Heapsort, Counting Sort |
| **07_Graph_Algorithms** | Network analysis | Dijkstra, Bellman-Ford, Kruskal, DFS/BFS |
| **08_Dynamic_Programming** | Optimal substructure | DP, Memoization, LCS, Knapsack, Edit Distance |
| **09_Greedy_Algorithms** | Local optimization | Activity Selection, Huffman, Interval Scheduling |
| **10_Geometric_Mathematical** | Math problems | Geometry, Number Theory, Combinatorics |

## 🎯 Key Features

✅ **Complete Solutions**: Each problem includes:
- Problem statement (inline comments)
- Optimized implementation
- Time & Space complexity analysis
- Example test cases with expected output

✅ **Learning-Focused**:
- Inline comments explaining key logic
- Multiple approaches for classic problems
- Trade-off discussions (time vs. space)

✅ **Competitive Programming Ready**:
- Fast I/O optimizations
- Edge case handling
- Tested on online judges

## 🚀 Notable Algorithms Covered

### Core Data Structures
- Balanced Binary Search Trees (AVL, Red-Black)
- Segment Trees with lazy propagation
- Suffix Arrays and Tries
- Union-Find (Disjoint Set Union)
- Binary Indexed Trees (Fenwick Trees)

### Graph Algorithms  
- Shortest Path: Dijkstra, Bellman-Ford, Floyd-Warshall
- Minimum Spanning Tree: Kruskal, Prim
- Traversal: DFS, BFS, Topological Sort
- Advanced: Strongly Connected Components, Flow Networks

### Dynamic Programming
- **Classic**: 0/1 Knapsack, Coin Change, LCS
- **Optimization**: DP on Trees, Digit DP
- **Game Theory**: Nim, Minimax
- **String**: Edit Distance, Pattern Matching

### Advanced Topics
- String Matching: KMP, Z-Algorithm, Rabin-Karp
- Matrix Exponentiation
- Bitmask DP
- Segment Tree DP

## 📊 Statistics

- **Total Problems**: 100+ solutions
- **Languages**: C++17
- **Verified**: Tested on Codeforces, AtCoder, SPOJ
- **Topics**: 10 major categories
- **Difficulty**: Beginner to Advanced (Codeforces 1200-2400)

## 💻 How to Use

### 1. Browse by Category
```bash
cd 08_Dynamic_Programming
ls -la
```

### 2. Study a Solution
```bash
cat knapsack_problem.cpp
```

Example structure:
```cpp
/*
Problem: 0/1 Knapsack
Input: n items, W capacity, weights[], values[]
Output: Maximum value achievable
Constraints: n <= 100, W <= 1000
Time: O(n*W) | Space: O(W)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    // Solution code...
    return 0;
}
```

### 3. Compile and Test
```bash
g++ -O2 -std=c++17 solution.cpp -o solution
./solution < input.txt
```

## 🎓 Learning Path (Recommended)

**Beginner** (1-3 weeks)
1. Linear Data Structures (01)
2. Sorting Algorithms (06)
3. Basic Search (05)

**Intermediate** (3-8 weeks)
1. Tree Structures (02)
2. Graph Basics (03, 07)
3. Dynamic Programming (08)

**Advanced** (8-12 weeks)
1. Advanced Data Structures (04)
2. Complex DP (08)
3. Greedy Algorithms (09)
4. Geometric/Math (10)

## 🔧 Optimization Techniques Used

- **Fast I/O**: `ios_base::sync_with_stdio(false)`
- **Memory**: Pass by reference, avoid unnecessary copies
- **Time**: Early termination, pruning, bit manipulation
- **Algorithms**: Space-time trade-offs, mathematical insights

## 📚 Complexity Reference

| Operation | Best Case | Average | Worst Case | Space |
|---|---|---|---|---|
| Array Access | O(1) | O(1) | O(1) | O(n) |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| Quicksort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Mergesort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Dijkstra | - | O(E log V) | O(E log V) | O(V) |
| Floyd-Warshall | - | O(V³) | O(V³) | O(V²) |

## 🏆 Recognition

These solutions have been tested on:
- Codeforces (Division 2, rating 1600+)
- AtCoder (Beginner/Regular contests)
- SPOJ (Classical problems)
- LeetCode (Premium problems)

## 📝 Contributing

Solutions follow C++17 standards with:
- Clear variable names
- Comments for non-obvious logic
- Time/Space complexity in header
- Multiple test cases

## ⚖️ License

MIT License - see LICENSE file for details

## 👤 Author

Mobin Ghorbani

---

**Pro Tips**:
1. ⭐ Don't memorize solutions - understand the approach
2. 🧠 Try problems before looking at solutions
3. 📈 Progress from simple to complex categories
4. 🔄 Revisit solutions after 1-2 weeks
5. 💡 Adapt solutions to different problem variations