class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        bool flag=true;
        int t=0;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                // swap(nums[i-1],nums[i]);
                flag=false;
                t=i-1;
                break;
            }
            
        }
        if(flag==true)
        {


        reverse(nums.begin(),nums.end());
        }
        else
        {
            for(int i=n-1;i>t;i--)
            {
                if(nums[t]<nums[i])
                {
                    swap(nums[t],nums[i]);
                    break;
                }
            }
            reverse(nums.begin()+t+1,nums.end());
        }
    }
};