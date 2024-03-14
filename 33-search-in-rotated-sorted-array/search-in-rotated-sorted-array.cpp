class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st=0;
        int n=nums.size();
        int end=n-1;
        while(st<=end)
        {
            int mid=(st+end)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            //left sorted
            if(nums[st]<=nums[mid])
            {
                if(target<=nums[mid] && target>=nums[st])
                {
                        end=mid-1;
                }
                else
                {
                    st=mid+1;
                }
            }
            //right sorted
            else
            {
                if(target>=nums[mid] && target<=nums[end])
                {
                    st=mid+1;
                }
                else
                {
                        end=mid-1;
                }

            }
        }
        return -1;
    }
};