class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid=-1;
        int n=nums.size();
        int end=n-1;
        int start=0;
        
        while(end>=start)
        {
            mid=(end+start)/2;
            if(target==nums[mid])return mid;
            else if(target>nums[mid])
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