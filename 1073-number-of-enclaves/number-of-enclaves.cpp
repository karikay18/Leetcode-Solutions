class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = delrow[i] + r;
                int ncol = delcol[i] + c;

                if (ncol >= 0 && ncol < grid[0].size() && nrow >= 0 && nrow < grid.size() && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                bfs(i, 0, vis, grid);
            }
            if (grid[i][m - 1] == 1 && !vis[i][m - 1]) {
                bfs(i, m - 1, vis, grid);
            }
        }

        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && !vis[0][i]) {
                bfs(0, i, vis, grid);
            }
            if (grid[n - 1][i] == 1 && !vis[n - 1][i]) {
                bfs(n - 1, i, vis, grid);
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
