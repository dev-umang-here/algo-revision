class Solution {
    vector<int> dir = {0, 1, 0, -1, 0};
    int n, m;

public:
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& vis) {
        if (vis[i][j] != -1) return vis[i][j];

        int ans = 0;
        for (int k = 0; k < 4; k++) {
            int dx = i + dir[k];
            int dy = j + dir[k + 1];

            if (dx >= 0 && dy >= 0 && dx < n && dy < m && matrix[dx][dy] > matrix[i][j]) {
                ans = max(ans, dfs(matrix, dx, dy, vis));
            }
        }
        return vis[i][j] = ans + 1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(matrix, i, j, vis));
            }
        }
        return ans;
    }
};
