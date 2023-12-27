class Solution {
public:
    int maxProfit(vector<int>& nums) {
       int left=0; 
       int right=0; 
       int profit=INT_MIN;
       int maxp=INT_MIN;
       while(left<nums.size() && right<nums.size())
       {
           profit=nums[right]-nums[left];
           maxp=max(profit,maxp);
           if(profit<0)
           {
               profit=0;
               left++;
           }
           else{
               right++;
           }
       }
       return maxp;
    }
};