class Solution {
public:
    Node* DeepCopy(Node* node, unordered_map<Node*, Node*>& vis) {
        if (vis.find(node) != vis.end())
            return vis[node]; // why this needed because we have to add already
                              // visited to this neighour also
        Node* clone = new Node(node->val, {});
        vis[node] = clone;
        // vis[node]=1;
        for (auto neigh : node->neighbors) {
            clone->neighbors.push_back(DeepCopy(neigh, vis));
        }
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;
        unordered_map<Node*, Node*> vis;
        return DeepCopy(node, vis);
    }
};

/*
    Problem: Clone Graph
    Approach: DFS
    Time Complexity: O(V + E)
    Space Complexity: O(V)
    where V is the number of vertices and E is the number of edges

    Using DFS to clone the graph.
    Use a map to store the original node and the cloned node. and also return not add condition 
    like if(!visited[node]) because that will not push the current node to neighours
*/