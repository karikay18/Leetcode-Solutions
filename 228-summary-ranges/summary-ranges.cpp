class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if (n == 0) return res;
        
        int s = 0;
        while (s < n) {
            int e = s;
            while (e + 1 < n && nums[e + 1] == nums[e] + 1) {
                e++;
            }
            if (s == e) {
                res.push_back(to_string(nums[s]));
            } else {
                res.push_back(to_string(nums[s]) + "->" + to_string(nums[e]));
            }
            s = e + 1;
        }
        return res;
    }
};