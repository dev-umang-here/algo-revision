class Solution {
public:
    int dir[5] = {0, 1, 0, -1, 0};

    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        grid[i][j] = '0'; // mark as visited

        for (int k = 0; k < 4; ++k) {
            int x = i + dir[k];
            int y = j + dir[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1') {
                dfs(grid, x, y, n, m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j, n, m); // Start DFS from this unvisited land
                }
            }
        }

        return ans;
    }
};
