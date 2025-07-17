bool dfs(int node, int color, vector<vector<int>>& graph, vector<int>& colors) {
    colors[node] = color;

    for (int neigh : graph[node]) {
        if (colors[neigh] == -1) {
            if (!dfs(neigh, 1 - color, graph, colors)) return false;
        } else if (colors[neigh] == color) {
            return false; // same color neighbor → not bipartite
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> colors(n, -1); // -1 = unvisited

    for (int i = 0; i < n; ++i) {
        if (colors[i] == -1) {
            if (!dfs(i, 0, graph, colors)) return false;
        }
    }

    return true;
}
