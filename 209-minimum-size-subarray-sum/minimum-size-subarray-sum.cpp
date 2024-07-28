class Solution {
public:
   

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;  // Initialize res to a large value
        int i = 0;
        int sum = 0;  // This will keep the sum of the current window

        for (int j = 0; j < n; j++) {
            sum += nums[j];  // Expand the window by including nums[j]

            while (sum >= target) {  // Shrink the window from the left
                res = min(res, j - i + 1);
                sum -= nums[i];
                i++;
            }
        }

        return res == INT_MAX ? 0 : res;  // If res is unchanged, return 0
    }
};
