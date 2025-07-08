
/*
    Problem: Detect cycle in an undirected graph
    Approach: BFS
    Time Complexity: O(V + E)
    Space Complexity: O(V)
    where V is the number of vertices and E is the number of edges

    Keep parent information and if a node is already visited and is not the parent of the current node, then there is a cycle.
*/
class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                queue<pair<int, int>> q;
                q.push({i, -1});
                vis[i] = 1;
                while (!q.empty()) {
                    auto top = q.front();
                    int node = top.first;
                    int parent = top.second;
                    q.pop();
                    for (auto neigh : adj[node]) {
                        if (!vis[neigh]) {
                            vis[neigh] = 1;
                            q.push({neigh, node});
                        } else if (neigh != parent) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
