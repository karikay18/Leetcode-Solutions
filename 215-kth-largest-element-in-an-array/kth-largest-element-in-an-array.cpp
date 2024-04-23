class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        //for(auto it:nums)
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        int p=k-1;
        while(p>0)
        {
            pq.pop();
            p--;
        }
        return pq.top();
    }
};