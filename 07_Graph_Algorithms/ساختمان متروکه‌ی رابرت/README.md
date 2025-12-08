# 📖 Problem Description
Marcus and Robert have entered an abandoned building. The building's map is represented as a rectangular grid of cells with dimensions n × m. Each cell is either:

A wall (#)

A walkable floor (.)

They want to determine how many rooms exist in the building. A room is defined as a maximally connected component of floor cells, where two cells are considered connected if they are adjacent in the four cardinal directions (up, down, left, right).

Every time Robert steps onto a floor cell that hasn't been visited before, Marcus exclaims: "This is a new room!" and they proceed to explore all floor cells connected to it to identify the entire room.

# 🎯 Input/Output Format
Input
First line: Two integers n and m (1 ≤ n, m ≤ 1000)

Next n lines: Each containing a string of length m consisting of # and .

Output
A single integer: The number of rooms (connected components of floor cells) in the building.

### 📊 Examples
Example 1
```
Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3
```
# Explanation:
The building has 3 rooms of connected floor cells:

Room 1: Top-left cluster (cells (1,1), (1,2), (1,3))

Room 2: Top-right cluster (cells (1,5), (1,6), (1,7), (3,5), (3,6), (3,7))

Room 3: Middle cluster (cell (3,1), (3,2), (3,3))
