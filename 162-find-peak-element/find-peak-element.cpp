class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size()==1)return 0;
        int n=nums.size();
        // if(nums.size()==2) return ;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        int l=1;
        int r=nums.size()-2;

        while(l<=r)
        {
            int mid=(r+l)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
            {
                return mid;
            }
            if(nums[mid]>nums[mid-1])
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
            
        }
        return -1;;
    }
};