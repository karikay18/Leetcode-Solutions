class Solution {
public:
    void solve(int ind,vector<int>&ds,vector<vector<int>>&ans,int target,vector<int>& candidates)
    {
        if(ind==candidates.size())
        {
            if(target==0)ans.push_back(ds);
            return;
        }
        if(candidates[ind]<=target)
        {

        ds.push_back(candidates[ind]);
        solve(ind,ds,ans,target-candidates[ind],candidates);
        ds.pop_back();
        }
        solve(ind+1,ds,ans,target,candidates);


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     vector<vector<int>>ans;
     vector<int>ds;
     solve(0,ds,ans,target,candidates);
     return ans;   
    }
};