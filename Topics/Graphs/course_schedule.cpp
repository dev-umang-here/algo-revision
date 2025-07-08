/*
Problem: Course Schedule
Platform: LeetCode
Difficulty: Medium
Link: https://leetcode.com/problems/course-schedule/
Company: Google, Amazon, Microsoft, Meta, Apple, Uber
Topics: Graph, Topological Sort, DFS, BFS, Cycle Detection

Problem Description:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must
take course bi first if you want to take course ai. Return true if you can finish all courses.

Example:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: Take course 0 first, then course 1.

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: Cycle exists - cannot complete both courses.

Time Complexity: O(V + E) where V = courses, E = prerequisites
Space Complexity: O(V + E) for adjacency list and auxiliary data structures

Approach:
1. Build adjacency list from prerequisites
2. Use topological sort to detect cycles
3. DFS approach: Use 3 states (unvisited, visiting, visited)
4. BFS approach: Use Kahn's algorithm with in-degrees
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // TODO: Implement DFS approach - Cycle Detection using 3 states
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Your implementation here
        return false;
    }
    
    // TODO: Implement BFS approach - Kahn's Algorithm (Alternative)
    bool canFinishBFS(int numCourses, vector<vector<int>>& prerequisites) {
        // Your implementation here
        return false;
    }
    
    // TODO: Bonus - Course Schedule II - Return the order
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Your implementation here
        return {};
    }

private:
    // TODO: Implement cycle detection helper
    bool hasCycle(vector<vector<int>>& graph, int course, vector<int>& state) {
        // Your implementation here
        return false;
    }
};

// Helper functions
void printPrerequisites(const vector<vector<int>>& prerequisites) {
    cout << "Prerequisites: [";
    for (size_t i = 0; i < prerequisites.size(); i++) {
        cout << "[" << prerequisites[i][0] << "," << prerequisites[i][1] << "]";
        if (i < prerequisites.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void printOrder(const vector<int>& order) {
    cout << "Course Order: [";
    for (size_t i = 0; i < order.size(); i++) {
        cout << order[i];
        if (i < order.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Test cases and driver code
int main() {
    Solution solution;
    
    // Test Case 1: Valid schedule
    cout << "=== Test Case 1 ===" << endl;
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    printPrerequisites(prerequisites1);
    
    bool result1 = solution.canFinish(numCourses1, prerequisites1);
    cout << "Can finish: " << (result1 ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    // Test Case 2: Cycle exists
    cout << "=== Test Case 2 ===" << endl;
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    printPrerequisites(prerequisites2);
    
    bool result2 = solution.canFinish(numCourses2, prerequisites2);
    cout << "Can finish: " << (result2 ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;
    
    // Test Case 3: Complex valid schedule
    cout << "=== Test Case 3 ===" << endl;
    int numCourses3 = 4;
    vector<vector<int>> prerequisites3 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    printPrerequisites(prerequisites3);
    
    bool result3 = solution.canFinish(numCourses3, prerequisites3);
    cout << "Can finish: " << (result3 ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    return 0;
}

/*
Implementation Notes:
- DFS approach uses cycle detection with 3 states (white, gray, black)
- BFS approach (Kahn's algorithm) uses topological sorting
- Both approaches have same time/space complexity
- DFS is more intuitive for cycle detection
- BFS naturally gives you the topological order
- Common follow-ups: Course Schedule II, Minimum semesters needed
- Real-world applications: Build systems, dependency resolution
*/ 