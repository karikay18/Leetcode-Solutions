class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int maxele=arr[n-1];
        vector<int> ans;
        ans.push_back(-1);
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>maxele)
            {
                ans.push_back(maxele);
                maxele=arr[i];
            }
            else
            {
                ans.push_back(maxele);
                
            }
        } 
  reverse(ans.begin(),ans.end());
            return ans;
    }
};