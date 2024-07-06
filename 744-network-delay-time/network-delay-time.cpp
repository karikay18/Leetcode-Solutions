

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& time : times) {
            adj[time[0]].emplace_back(time[1], time[2]);
        }

        vector<int> mtime(n + 1, INT_MAX);
        mtime[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, k);

        while (!pq.empty()) {
            auto [current_time, node] = pq.top();
            pq.pop();

            if (current_time > mtime[node]) continue;

            for (auto& [next_node, travel_time] : adj[node]) {
                int new_time = current_time + travel_time;
                if (new_time < mtime[next_node]) {
                    mtime[next_node] = new_time;
                    pq.emplace(new_time, next_node);
                }
            }
        }

        int max_time = 0;
        for (int i = 1; i <= n; ++i) {
            if (mtime[i] == INT_MAX) return -1;
            max_time = max(max_time, mtime[i]);
        }

        return max_time;
    }
};
