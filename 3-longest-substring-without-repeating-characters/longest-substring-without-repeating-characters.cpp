class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=-1;
     int len=0;
     vector<int>v(256,-1);
     for(int i=0;i<s.size();i++)
       {
           if(v[s[i]]>start)
                start=v[s[i]];
            v[s[i]]=i;



         len=max(len,i-start);
       }

       return len;
    }
};