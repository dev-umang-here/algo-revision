/*
Problem: Clone Graph
Platform: LeetCode
Difficulty: Medium
Link: https://leetcode.com/problems/clone-graph/
Company: Google, Amazon, Microsoft, Meta, Apple, Uber, LinkedIn
Topics: Graph, DFS, BFS, Hash Table

Problem Description:
Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

Example:
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph. Node 1 is connected to nodes 2 and 4...

Time Complexity: O(N + M) where N = nodes, M = edges
Space Complexity: O(N) for the hash map storing cloned nodes

Approach:
1. Use DFS/BFS to traverse original graph
2. Create new nodes and maintain mapping from original to cloned
3. Build connections between cloned nodes using the mapping
4. Handle cycles by checking if node already cloned
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

// Definition for a Node
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    // TODO: Implement DFS approach - Most Intuitive
    Node* cloneGraph(Node* node) {
        // Your implementation here
        return nullptr;
    }
    
    // TODO: Implement BFS approach - Alternative
    Node* cloneGraphBFS(Node* node) {
        // Your implementation here
        return nullptr;
    }
    
    // TODO: Implement Iterative DFS using Stack
    Node* cloneGraphIterative(Node* node) {
        // Your implementation here
        return nullptr;
    }

private:
    // TODO: Implement DFS helper function
    Node* dfsClone(Node* node, unordered_map<Node*, Node*>& cloneMap) {
        // Your implementation here
        return nullptr;
    }
};

// Helper functions for testing
Node* createGraph() {
    // Create test graph: 1-2-3-4-1 (cycle)
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};
    
    return node1;
}

void printGraph(Node* node, unordered_set<Node*>& visited) {
    if (!node || visited.count(node)) return;
    
    visited.insert(node);
    
    cout << "Node " << node->val << " -> neighbors: [";
    for (size_t i = 0; i < node->neighbors.size(); i++) {
        cout << node->neighbors[i]->val;
        if (i < node->neighbors.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    for (Node* neighbor : node->neighbors) {
        printGraph(neighbor, visited);
    }
}

void printGraph(Node* node) {
    if (!node) {
        cout << "Empty graph" << endl;
        return;
    }
    
    unordered_set<Node*> visited;
    printGraph(node, visited);
}

// Test cases and driver code
int main() {
    Solution solution;
    
    // Test Case 1: Standard graph with cycle
    cout << "=== Test Case 1: Graph with Cycle ===" << endl;
    Node* original = createGraph();
    
    cout << "Original Graph:" << endl;
    printGraph(original);
    cout << endl;
    
    Node* cloned1 = solution.cloneGraph(original);
    cout << "Cloned Graph:" << endl;
    printGraph(cloned1);
    
    cout << "Different memory addresses: " << (original != cloned1 ? "YES" : "NO") << endl << endl;
    
    // Test Case 2: Single node
    cout << "=== Test Case 2: Single Node ===" << endl;
    Node* singleNode = new Node(42);
    
    Node* clonedSingle = solution.cloneGraph(singleNode);
    cout << "Original: Node " << singleNode->val << endl;
    if (clonedSingle) {
        cout << "Cloned: Node " << clonedSingle->val << endl;
        cout << "Different addresses: " << (singleNode != clonedSingle ? "YES" : "NO") << endl;
    } else {
        cout << "Cloned: NULL" << endl;
    }
    cout << endl;
    
    // Test Case 3: Empty graph
    cout << "=== Test Case 3: Empty Graph ===" << endl;
    Node* clonedEmpty = solution.cloneGraph(nullptr);
    cout << "Cloned empty graph: " << (clonedEmpty == nullptr ? "NULL (correct)" : "NOT NULL") << endl;
    
    return 0;
}

/*
Implementation Notes:
- Key insight: Use hash map to track original -> clone mapping
- DFS approach is most intuitive and commonly expected
- BFS approach processes level by level
- Must handle cycles properly (check if node already cloned)
- All approaches have same time/space complexity
- Common follow-ups: Clone Binary Tree, Deep Copy of Complex Data Structures
- Real-world applications: Object serialization, graph databases
- Memory management: In production, implement proper cleanup
*/ 