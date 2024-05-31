class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        
        // Count the frequency of each number
        for (int num : nums) {
            mpp[num]++;
        }
        
        // Find the numbers that appear exactly once
        for (auto it : mpp) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};
