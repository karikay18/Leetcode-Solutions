class Solution {
public:
    int maxProductDifference(vector<int>& nums) {

        size_t size = nums.size();

        sort(nums.begin(), nums.end());
        return nums[size - 1] * nums[size - 2] - nums[0] * nums[1];   
    }
};