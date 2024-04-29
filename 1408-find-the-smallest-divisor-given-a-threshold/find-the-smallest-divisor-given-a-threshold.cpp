class Solution {
public:
    int solve(int d, vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += ceil(static_cast<double>(nums[i]) / static_cast<double>(d));
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int t) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            mini = min(nums[i], mini);
            maxi = max(nums[i], maxi);
        }
        int r = maxi;
        int l = 1;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2; // Corrected calculation of mid
            int sum = solve(mid, nums);
            if (sum <= t) {
                r = mid - 1;
                ans = mid; // Update the answer
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};