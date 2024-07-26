class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int cnt=0;
        int maxi=0;
        for(int i=0;i<citations.size();i++)
        {
            cnt=0;
            for(int j=0;j<citations.size();j++)
            {
                if(citations[j]>=citations[i])
                {
                    cnt++;
                }
                if(cnt<=citations[i])
            {
                maxi=max(cnt,maxi);
            }
            }
            
        }
        return maxi;
    }
};