class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int mid=-1;
        int n=nums.size()-1;
        int start=0;
        int end=n;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(target==nums[mid])
            {
                return true;
            }
            if((nums[start] == nums[mid]) && (nums[end] == nums[mid]))
            {
                start++;
                end--;
            }
            else if(nums[mid]>=nums[start])
            {
                if(nums[start]<=target && target<nums[mid])
                {
                    end=mid-1;
                }
                else
                {
                    start=mid+1;
                }
               
            }
            else
            {
                if(nums[end]>=target && target>nums[mid])
                {
                    start=mid+1;
                }
                else
                {
                    end=mid-1;
                }
                
            }
        }
        return false;
    }
};