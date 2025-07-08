bool ValidTree(int V, vector<vector<int>>& edges) {
    if (edges.size() != V - 1) return false; // Tree must have exactly V - 1 edges

    vector<vector<int>> adj(V);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int> vis(V, 0);
    queue<pair<int, int>> q;
    q.push({0, -1});
    vis[0] = 1;

    while (!q.empty()) {
        auto [node, parent] = q.front();
        q.pop();

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                vis[neigh] = 1;
                q.push({neigh, node});
            } else if (neigh != parent) {
                return false; // cycle detected
            }
        }
    }

    // Check if all nodes were visited (i.e., graph is connected)
    for (int i = 0; i < V; ++i) {
        if (!vis[i]) return false;
    }

    return true;
}