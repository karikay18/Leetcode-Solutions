class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;
        if (obstacleGrid[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        int pathsFromAbove = helper(i-1, j, obstacleGrid, dp);
        int pathsFromLeft = helper(i, j-1, obstacleGrid, dp);
        return dp[i][j] = pathsFromAbove + pathsFromLeft;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m-1, n-1, obstacleGrid, dp);
    }
};