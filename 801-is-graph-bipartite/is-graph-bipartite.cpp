class Solution {
public: 
    bool dfs(int start, int color, vector<vector<int>>& graph, vector<int>& vis) {
        vis[start] = color;
        for (auto it : graph[start]) {
            if (vis[it] == -1) {
                if (!dfs(it, 1 - color, graph, vis)) {
                    return false;
                }
            } else if (vis[it] == color) {
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (vis[i] == -1) {
                if (!dfs(i, 0, graph, vis)) {
                    return false;
                }
            }
        }
        return true;
    }
};
