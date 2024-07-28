class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int n=s.size();
        int maxi=0;
        int i=0;
        int j=0;
        while(i<s.size())
        {
            if(st.find(s[i])==st.end())
            {
                while(st.find(s[i])==st.end() && i<n)
                {
                    st.insert(s[i]);
                    i++;
                }
                maxi=max(maxi,i-j);
            }
            
            else
            {
                // while(st.find(s[j])!=st.end() && j<n)
                // {
                    st.erase(s[j]);
                    j++;
                // }
            }
           
        }
        return maxi;
    }
};