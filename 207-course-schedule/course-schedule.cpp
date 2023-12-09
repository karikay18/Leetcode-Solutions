class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        vector<int> indegree(n, 0);

        // Populate the adjacency list and calculate indegrees
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); // Assuming prerequisites are given as pairs [a, b] where b is a prerequisite for a
            indegree[it[0]]++;
        }

        queue<int> q;
        // Push nodes with 0 indegree into the queue
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            // Decrement indegree of adjacent nodes and push if their indegree becomes 0
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If the size of topo is equal to n, it means all courses can be completed
        return topo.size() == n;
    }
};