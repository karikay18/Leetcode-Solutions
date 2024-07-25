class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n =nums.size();
        int st=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                nums[st]=nums[i];
                st++;
            }
        }

        return st;
        
    }
};