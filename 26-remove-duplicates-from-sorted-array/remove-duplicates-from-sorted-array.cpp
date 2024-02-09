class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s;
        int k=0;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        k=s.size();
        int j = 0;
        for (int x: s) {
            nums[j++] = x;
        }
        return k;
    }
};