class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    long long up = (i > 0) ? dp[i-1][j] : 0;
                    long long left = (j > 0) ? dp[i][j-1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};