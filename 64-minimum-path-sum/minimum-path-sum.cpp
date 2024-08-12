class Solution {
public:
int helper(int m,int n,vector<vector<int>>& grid,vector<vector<int>>&dp)
{
    if(m<0 || n<0)
    {
        return INT_MAX;
    }
    if(m==0 && n==0)
    {
        return grid[0][0];
    }
    if(dp[m][n]!=-1)return dp[m][n];
    int left=0;
    int up=0;
   
    
        left=helper(m-1,n,grid,dp);


    
   
    
        up=helper(m,n-1,grid,dp);
    
    return dp[m][n]=min(left,up)+grid[m][n];
}
    int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size(); 
       int n=grid[0].size();
       vector<vector<int>>dp(m,vector<int>(n,-1));
       return helper(m-1,n-1,grid,dp); 
    }
};