class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>hash;
        int maxi=0;
        int l=0;
        // int r=1;
        for(int i=0;i<s.size();i++)
        {
            if(hash.find(s[i])!=hash.end())
            {
                while( hash.find(s[i])!=hash.end())
                {
                    hash.erase(s[l]);
                    l++;
                }

            }
            hash.insert(s[i]);
            maxi=max(maxi,i-l+1);
        }
        return maxi;
    }
};