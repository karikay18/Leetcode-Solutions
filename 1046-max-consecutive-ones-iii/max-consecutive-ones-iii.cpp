class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int flip=0;
        // int r=0;
        int res=0;
        while(r<nums.size())
        {
            if(nums[r]==0)
            {
                flip++;
            }
            if(flip>k)
            {
                if(nums[l]==0)
                {
                    flip--;
                }   
                l++;
            }
            r++;

            res=max(res,r-l);
        }
        return res;
    }
};