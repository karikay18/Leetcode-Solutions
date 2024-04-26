class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        stack<int>st;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--)
        {
            int ele=nums2[i];
            while(!st.empty() && st.top()<=ele)
            {
                st.pop();

            }
            int res=(st.empty())?-1:st.top();
            mpp.insert({ele,res});
            st.push(ele);

        }
        vector<int>ans;
        for(auto x:nums1)
        {
            ans.push_back(mpp[x]);
        }
        return ans;
    }
};