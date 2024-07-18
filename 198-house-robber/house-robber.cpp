class Solution {
public:
int solve(vector<int>& nums,int node,vector<int>&dp)
{
    if(node==0)return nums[node];
    if(node<0)return 0;
    if(dp[node]!=-1)return dp[node];
    int pick=nums[node]+solve(nums,node-2,dp);
    int npick=solve(nums,node-1,dp);
    return dp[node]=max(pick,npick);

}
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,nums.size()-1,dp);
    }
};