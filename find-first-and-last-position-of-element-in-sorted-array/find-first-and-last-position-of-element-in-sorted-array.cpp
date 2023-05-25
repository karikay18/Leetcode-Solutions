class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int mid = -1;
        int start = 0;
        int n = nums.size();
        int end = n - 1;

        while (end >= start) {
            mid = (start + end) / 2;

            if (nums[mid] == target) {
                break;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        if (end < start) {
            return {-1, -1};
        }

        start = mid;
        end = mid;

        while (start >= 0 && nums[start] == target) {
            start--;
        }

        while (end < n && nums[end] == target) {
            end++;
        }

        ans.push_back(start + 1);
        ans.push_back(end - 1);

        return ans;
    }
};
