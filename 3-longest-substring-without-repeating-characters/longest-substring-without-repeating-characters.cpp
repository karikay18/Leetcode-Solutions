class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mpp(256,-1);
        int left=-1;
        int len=0;
        for(int right=0;right<s.size();right++)
        {
           if(left<mpp[s[right]])
           {
               left=mpp[s[right]];
           }
            mpp[s[right]]=right;
            len=max(len,-left+right);
        }
        return len;
    }
};