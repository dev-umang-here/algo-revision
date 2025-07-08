# Graph Problems - Senior Developer Interview Focus

## 📊 Statistics
- **Total Problems**: 4
- **Easy**: 0
- **Medium**: 3
- **Hard**: 1

## 📝 Problem List

| # | Problem | Difficulty | Solution | Platform | Companies | Key Concepts |
|---|---------|------------|----------|----------|-----------|--------------|
| 1 | [Number of Islands](number_of_islands.cpp) | Medium | [Solution](number_of_islands.cpp) | LeetCode | Amazon, Google, Microsoft, Meta | DFS, BFS, Connected Components |
| 2 | [Course Schedule](course_schedule.cpp) | Medium | [Solution](course_schedule.cpp) | LeetCode | Google, Amazon, Microsoft, Meta | Topological Sort, Cycle Detection |
| 3 | [Word Ladder](word_ladder.cpp) | Hard | [Solution](word_ladder.cpp) | LeetCode | Google, Amazon, Microsoft, Meta | BFS, Shortest Path, String Manipulation |
| 4 | [Clone Graph](clone_graph.cpp) | Medium | [Solution](clone_graph.cpp) | LeetCode | Google, Amazon, Microsoft, Meta | DFS, BFS, Hash Table, Deep Copy |

## 🎯 Key Concepts Covered

### **Traversal Algorithms**
- [x] **Depth-First Search (DFS)** - Connected components, cycle detection
- [x] **Breadth-First Search (BFS)** - Shortest path in unweighted graphs
- [x] **Iterative DFS** - Stack-based traversal

### **Advanced Graph Algorithms** 
- [x] **Topological Sort** - Course scheduling, dependency resolution
- [x] **Cycle Detection** - Prerequisites validation
- [x] **Shortest Path** - Word transformation, social networks
- [x] **Graph Cloning** - Deep copy with cycle handling

### **Data Structures Used**
- [x] **Adjacency List** - Efficient graph representation
- [x] **Hash Table** - O(1) lookups, visited tracking
- [x] **Queue** - BFS implementation
- [x] **Stack** - Iterative DFS
- [x] **Set** - Visited nodes, word dictionaries

## 💡 Common Interview Patterns

### **1. Connected Components (DFS/BFS)**
```cpp
// Pattern: Mark all connected nodes
void dfs(grid, i, j) {
    if (out_of_bounds || visited) return;
    mark_visited(i, j);
    // Explore neighbors
    dfs(grid, i+1, j); dfs(grid, i-1, j);
    dfs(grid, i, j+1); dfs(grid, i, j-1);
}
```
- **When to use**: Islands, regions, connected components
- **Time**: O(V + E), **Space**: O(V) for recursion

### **2. Topological Sort (Cycle Detection)**
```cpp
// Pattern: 3-state DFS for cycle detection
bool hasCycle(node, state) {
    if (state[node] == VISITING) return true;  // Back edge
    if (state[node] == VISITED) return false;
    
    state[node] = VISITING;
    for (neighbor : graph[node]) {
        if (hasCycle(neighbor, state)) return true;
    }
    state[node] = VISITED;
    return false;
}
```
- **When to use**: Prerequisites, dependencies, DAG validation
- **Time**: O(V + E), **Space**: O(V)

### **3. BFS Shortest Path**
```cpp
// Pattern: Level-by-level exploration
int bfs(start, end) {
    queue<node> q; q.push(start);
    set<node> visited; visited.insert(start);
    int level = 0;
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            node current = q.front(); q.pop();
            if (current == end) return level;
            // Add unvisited neighbors
        }
        level++;
    }
    return -1;
}
```
- **When to use**: Shortest path, minimum steps, transformations
- **Time**: O(V + E), **Space**: O(V)

### **4. Graph Cloning with Cycles**
```cpp
// Pattern: Hash map for original -> clone mapping
Node* clone(Node* node, map<Node*, Node*>& cloneMap) {
    if (cloneMap.count(node)) return cloneMap[node];
    
    Node* newNode = new Node(node->val);
    cloneMap[node] = newNode;
    
    for (Node* neighbor : node->neighbors) {
        newNode->neighbors.push_back(clone(neighbor, cloneMap));
    }
    return newNode;
}
```
- **When to use**: Deep copy, object cloning, serialization
- **Time**: O(V + E), **Space**: O(V)

## 🚀 Senior-Level Follow-ups

### **Number of Islands Variants**
- Number of Islands II (Dynamic connectivity)
- Max Area of Island
- Number of Distinct Islands

### **Course Schedule Extensions**  
- Course Schedule II (Return order)
- Minimum semesters needed
- Parallel course completion

### **Word Ladder Advanced**
- Word Ladder II (All shortest paths)
- Bidirectional BFS optimization
- Word Break problems

### **Clone Graph Extensions**
- Clone Binary Tree with Random Pointers
- Deep Copy of Complex Data Structures
- Serialize/Deserialize graphs

## 🎯 Interview Tips

### **Problem Recognition**
- **Grid/Matrix + Connected regions** → DFS/BFS (Islands pattern)
- **Prerequisites/Dependencies** → Topological Sort
- **Shortest path in unweighted graph** → BFS
- **Deep copy with references** → DFS with hash map

### **Optimization Techniques**
- **Bidirectional BFS** for shortest path (Word Ladder)
- **Early termination** in cycle detection
- **In-place marking** to save space (Islands)
- **Set operations** for O(1) lookups

### **Common Mistakes to Avoid**
- Forgetting to handle cycles in DFS
- Not using proper visited tracking
- Incorrect level counting in BFS
- Memory leaks in graph cloning

## 🔗 Related Topics

- **Arrays**: Matrix traversal, 2D grid problems
- **Trees**: DFS/BFS concepts transfer directly
- **Dynamic Programming**: Graph DP problems
- **Union-Find**: Alternative for connectivity problems

## 📚 Advanced Learning Resources

- [Graph Theory Fundamentals](https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/)
- [Topological Sorting](https://www.geeksforgeeks.org/topological-sorting/)
- [Dijkstra's Algorithm](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/)
- [Graph Representations](https://www.geeksforgeeks.org/graph-and-its-representations/)

## 🎖️ Difficulty Progression

1. **Start with**: Number of Islands (foundational DFS/BFS)
2. **Then practice**: Course Schedule (topological sort concepts)
3. **Challenge yourself**: Clone Graph (complex traversal with cycles)
4. **Master level**: Word Ladder (advanced BFS with optimizations)

---
**💡 Pro Tip**: These 4 problems cover 80% of graph concepts asked in senior developer interviews. Master these patterns and you'll be well-prepared for any graph problem! 