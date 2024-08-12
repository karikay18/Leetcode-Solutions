class Solution {
public:
void dfs(int i,int j,vector<vector<char>>& grid)
{
     int m = grid.size();
        int n = grid[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
            return;
        }
    grid[i][j]='0';
    dfs(i-1,j,grid);
    dfs(i+1,j,grid);
    dfs(i,j-1,grid);
    dfs(i,j+1,grid);
}
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0 || grid[0].size()==0)
        {
            return 0;
        }
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    cnt++;
                }
            }

        }
        return cnt;
    }
};