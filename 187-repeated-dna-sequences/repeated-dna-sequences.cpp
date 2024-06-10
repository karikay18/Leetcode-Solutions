class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>res;
        if (s.size() < 10) return {};
        unordered_map<string,int>mpp;
        for(int i=0;i<=s.size()-10;i++)
        {
            string p=s.substr(i,10);
            mpp[p]++;
        }
        for(auto it:mpp)
        {
            if(it.second>1)
            {
                res.push_back(it.first);
            }
        }
        return res;
    }
};