class Solution {
public:
    void dfs(int start,vector<int>&vis,vector<vector<int>>&adj)
    {
        vis[start]=1;
        for(auto it:adj[start])
        {
            if(!vis[it])
            {

            dfs(it,vis,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
        {
            return -1;
        }
        // number of compinents count karna hai
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        // for(int i=0;i<n;i++)
        // {
            for(auto it:connections)
            {
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
        // }
        int components=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj);
                components++;
            }
        }
        return components-1;

    }
};