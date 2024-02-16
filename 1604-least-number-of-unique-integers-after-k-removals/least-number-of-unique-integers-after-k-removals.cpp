class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mpp;
        for(auto it:arr)
        {
            mpp[it]++;
        }
        vector<int>temp;
        for(auto it : mpp)
        {
            temp.push_back(it.second);
        }
        sort(temp.begin(),temp.end());
        int count = 0;

        for(int i=0;i<temp.size();i++){
            if(k > temp[i]){
                k -= temp[i];
                temp[i] = 0;
            }

            else{
                temp[i] -= k;
                k = 0;
            }

            if(temp[i] != 0){
                count++;
            }
        }

        return count;
        
    }
};