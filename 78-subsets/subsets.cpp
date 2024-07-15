class Solution {
public:
    void solve(int i,vector<int>& nums,vector<int>&subset,vector<vector<int>>&res)
    {
        if(i==nums.size())
        {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        solve(i+1,nums,subset,res);
        subset.pop_back();
        solve(i+1,nums,subset,res);


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        vector<vector<int>>res;
        solve(0,nums,subset,res);
        return res;
    }
};