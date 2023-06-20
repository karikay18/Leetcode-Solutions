class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>hash;
        for(int i=0;i<nums.size();i++)
        {
            hash.insert(nums[i]);
        }
        if(nums.size()>hash.size())return true;
        return false;
    }
};