class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int end=n-1;
        int start=0;
        int mid=-1;
        while(end>=start)
        {
            mid=(start+end)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target) end=mid-1;
            else start=mid+1;
        }
        return end+1;

    }
};