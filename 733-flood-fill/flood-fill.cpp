class Solution {
private:
void dfs(vector<vector<int>>& image,vector<vector<int>> &ans,int row,int col,int color,int delrow[],int delcol[], int ic)
{   
  int m=image.size();
  int n=image[0].size();
    ans[row][col]=color;
    for(int i=0;i<4;i++)
    {
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(ncol<n && nrow<m && ncol>=0 && nrow>=0 && ans[nrow][ncol]!=color && image[nrow][ncol]==ic)
        {
            dfs(image,ans,nrow,ncol,color,delrow,delcol,ic);
        }
    }

}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int ic=image[sr][sc];
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        dfs(image,ans,sr,sc,color,delrow,delcol,ic);
        return ans;
    }
};