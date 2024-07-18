class Solution {
public:
int solve(vector<int>& nums,int node)
{
    // if(node==0)return nums[node];
    // if(node<0)return 0;
    int prev=nums[0];
    int prev2=0;
    // int curi=0;
    // if(dp[node]!=-1)return dp[node];
    for(int i=1;i<nums.size();i++)
    {
        int pick=nums[i];
        if(node>1)pick+=+prev2;
        int npick=prev;
       int curi=max(npick,pick);
       prev2=prev;
       prev=curi;

    }
    return prev;

}
    int rob(vector<int>& nums) {
        // vector<int>dp(nums.size(),-1);
        return solve(nums,nums.size()-1);
    }
};