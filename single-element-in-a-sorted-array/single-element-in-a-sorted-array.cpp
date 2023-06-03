class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0;
        int n=nums.size();
        int mid;
        int end=n-1;
        if(n==1) return nums[0];
        if(nums[0]!=nums[1])
        {
            return nums[0];
        }
        else if (end==0)
        {
            return nums[0];
        }
        else if(nums[end]!=nums[end-1])
        {
            return nums[end];
        }

        while(start<=end)
        {
            mid=(start+end)/2;
            if(mid>1 && mid<n-1 && nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1] )
            {
                return nums[mid];
            }
            if(((mid%2)==0 && nums[mid]==nums[mid+1]) || ((mid%2)==1 && nums[mid]==nums[mid-1])  )
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return -1;
    }
};








// 1,1,2,3,3,4,4,8,8
// 0,1,2,3,4,5,6,7,8


// 3,3,7,7,10,11,11



