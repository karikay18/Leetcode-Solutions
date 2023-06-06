class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        // int i=2;
        int n=arr.size();
        int diff=(arr[1]-arr[0]);
        for(int j=2;j<n;j++)
        {

        
            if(diff!=(arr[j]-arr[j-1]))
            {
                return false;
            }
            // i++;
        }
        return true;
        
    }
};