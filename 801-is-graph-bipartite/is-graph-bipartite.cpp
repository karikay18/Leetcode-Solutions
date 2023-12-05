class Solution {
private:
    bool dfs(vector<int> &vis,int target,int col,vector<vector<int>>& graph)
    {   
    vis[target]=col;
    for(auto it:graph[target])
    {
        if(vis[it]==-1)
        {
            if(dfs(vis,it,!col,graph)==false)return false;
        }
        else if(vis[it]==col)
        {
            return false;
        }

    } 
    return true;

    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), -1);
        // int col=0;
        for(int i=0;i<graph.size();i++)
        {
            if(vis[i]==-1)
            {
                if(dfs(vis,i,0,graph)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};