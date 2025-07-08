/*
Problem: Number of Islands
Platform: LeetCode
Difficulty: Medium
Link: https://leetcode.com/problems/number-of-islands/
Company: Amazon, Google, Microsoft, Meta, Apple, Netflix
Topics: Graph, DFS, BFS, Matrix

Problem Description:
Given an m x n 2D binary grid which represents a map of '1's (land) and '0's (water),
return the number of islands. An island is surrounded by water and is formed by connecting
adjacent lands horizontally or vertically.

Example:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Time Complexity: O(m*n) where m = rows, n = columns
Space Complexity: O(m*n) worst case for DFS recursion stack

Approach:
1. Iterate through each cell in the grid
2. When we find a '1', increment island count and perform DFS/BFS
3. Mark all connected '1's as visited to avoid counting same island twice
4. Use DFS to explore all 4 directions from current cell
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    // TODO: Implement DFS approach (Most Common in Interviews)
    int numIslands(vector<vector<char>>& grid) {
        // Your implementation here
        return 0;
    }

    // TODO: Implement BFS approach (Alternative)
    int numIslandsBFS(vector<vector<char>>& grid) {
        // Your implementation here
        return 0;
    }

  private:
    // TODO: Implement DFS helper function
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        // Your implementation here
    }
};

// Helper functions
void printGrid(vector<vector<char>>& grid) {
    for (const auto& row : grid) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<char>> copyGrid(const vector<vector<char>>& original) {
    return original;
}

// Test cases and driver code
int main() {
    Solution solution;

    // Test Case 1
    vector<vector<char>> grid1 = {{'1', '1', '1', '1', '0'},
                                  {'1', '1', '0', '1', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '0', '0', '0'}};

    cout << "=== Test Case 1 ===" << endl;
    cout << "Grid:" << endl;
    auto grid1_copy = copyGrid(grid1);
    printGrid(grid1_copy);

    int result1 = solution.numIslands(grid1);
    cout << "Number of Islands: " << result1 << endl;
    cout << "Expected: 1" << endl << endl;

    // Test Case 2
    vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '1', '0', '0'},
                                  {'0', '0', '0', '1', '1'}};

    cout << "=== Test Case 2 ===" << endl;
    cout << "Grid:" << endl;
    auto grid2_copy = copyGrid(grid2);
    printGrid(grid2_copy);

    int result2 = solution.numIslands(grid2);
    cout << "Number of Islands: " << result2 << endl;
    cout << "Expected: 3" << endl << endl;

    // Add more test cases as needed

    return 0;
}

/*
Implementation Notes:
- DFS approach is more intuitive and commonly asked in interviews
- BFS approach uses O(min(m,n)) extra space for queue
- Both approaches modify the original grid; use visited array if preservation needed
- Time complexity is optimal - we visit each cell exactly once
- Can extend to count island sizes, find largest island, etc.
- Common follow-ups: Number of Islands II (dynamic), Max Area of Island
*/