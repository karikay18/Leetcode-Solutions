class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int n=nums.size()-1;
        int end=n;
        int mid=-1;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(nums[mid]==target)
            {

            return mid;
            }
            if(nums[mid]>=nums[start]) //left wala sorted hai
            {
                if(target>=nums[start] && target<=nums[mid])
                {

                 end=mid-1;
                }
                else
                {

                 start=mid+1;
                }


            }
            else //right wala sorted hai
            {
               if(target<=nums[end] && target>=nums[mid])
               {

               start=mid+1;
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