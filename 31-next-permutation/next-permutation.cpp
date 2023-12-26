class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int ind = -1;

        // Find the first decreasing element from the right
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                ind = i;
                break;
            }
        }

        if (ind == -1) {
            reverse(nums.begin(), nums.end()); // Reverse entire sequence
            return;
        }

        // Find the smallest element larger than nums[ind-1] to swap with
        for (int i = n - 1; i >= ind; i--) {
            if (nums[i] > nums[ind - 1]) {
                swap(nums[i], nums[ind - 1]);
                break;
            }
        }

        reverse(nums.begin() + ind, nums.end()); // Reverse the sequence from ind onwards
    }
};