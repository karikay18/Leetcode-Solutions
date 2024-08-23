class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int res=sum;
        // int j=0;
        for(int i=1;i<nums.size();i++)
        {
            res=max(sum,res);
            if(sum<0)
            {
                sum=0;
            }
            sum+=nums[i];


        }
                    res=max(sum,res);

        return res;
    }
};