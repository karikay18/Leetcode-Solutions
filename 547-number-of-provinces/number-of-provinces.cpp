class Solution {
private:
void dfs(int i,vector<int>&vis,vector<int>adjls[])
{
    vis[i]=1;
    for(auto it:adjls[i])
    {
        if(!vis[it])
        {
           dfs(it,vis,adjls); 
        }
    }
}
public:
    int findCircleNum(vector<vector<int>>& v) {
        int n=v.size();
        vector<int> adjls[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==1 && i!=j)
                {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }

        }
        vector<int> vis(n+1,0);
        int cnt=0;
       for (int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adjls);
            }
        }
        return cnt;
    }
};