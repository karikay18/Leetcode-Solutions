class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Sort intervals based on the start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        int s = intervals[0][0];
        int e = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= e) {
                // There is an overlap
                e = max(e, intervals[i][1]);
            } else {
                // No overlap, push the current interval to result
                res.push_back({s, e});
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }

        // Push the last interval
        res.push_back({s, e});

        return res;
    }
};
