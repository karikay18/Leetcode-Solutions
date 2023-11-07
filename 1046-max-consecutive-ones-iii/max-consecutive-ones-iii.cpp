class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int window=0;
        int ans=0;
        for(int r=0;r<nums.size();r++)
        {   
            window=window+nums[r];
            while(window+k<r-l+1)
            {
                window=window-nums[l];
                l++;
            }
            ans=max(ans,r-l+1);
        }

        return ans;
    }
};