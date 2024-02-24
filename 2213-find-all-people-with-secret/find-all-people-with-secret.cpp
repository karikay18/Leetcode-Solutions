
    int now;

struct CompareTuple {
    bool operator()(tuple<int, int, int>& lhs, tuple<int, int, int>& rhs) {
        return get<2>(lhs) > get<2>(rhs); 
    }
};

void find(int curr, vector<int> &vis, unordered_map<int, vector<int>> &adj)
{
    vis[curr] = now;

    for(int i=0; i<adj[curr].size(); ++i)
    {   
        int next = adj[curr][i];

        if(vis[next] != now)
            find(next, vis, adj);
    }
}

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int fp) {

        vector<int> res;
        vector<int> vis(n+1, 0); 

        vis[0] = -1; vis[fp] = -1; now = 2;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, CompareTuple> pq;
        unordered_map<int, vector<int>> adj;
        stack<int> start;
        
        for(int i=0; i<meet.size(); ++i)
            pq.push( {meet[i][0], meet[i][1], meet[i][2]} );
        
        while(!pq.empty())
        {
            int curr = get<2>(pq.top());
            unordered_map<int, vector<int>> adj;

            while(!pq.empty() && get<2>(pq.top()) == curr)
            {
                auto[p1, p2, time] = pq.top();

                adj[p1].push_back(p2);
                adj[p2].push_back(p1);

                if(vis[p1] != 0)
                    start.push(p1);
                if(vis[p2] != 0)
                    start.push(p2);

                pq.pop();
            }

            while(!start.empty())
            {
                int curr = start.top();
                start.pop();

                if(vis[curr] != now)
                    find(curr, vis, adj);
            }

            ++now;
        }

        for(int i=0; i<vis.size(); ++i)
            if(vis[i] != 0)
                res.push_back(i);

        return res;
    }

};