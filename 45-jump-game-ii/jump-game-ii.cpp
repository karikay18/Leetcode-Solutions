class Solution {
public:
    int jump(vector<int>& nums) {

        int count = 0;
        int reach = 0;
        int last = 0;

        int n = nums.size();

        for(int i=0; i<n-1; i++){
           
           reach = max(reach, i+nums[i]);

           if(i == last){
            last = reach;
            count++;
           }
        }
        
        return count;
    }
};