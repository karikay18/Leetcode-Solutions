class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int>mpp;
        int mf=0;
        int maxl=0;
        int l=0;

        for(int r=0;r<s.size();r++)
        {
            mpp[s[r]-'A']++;
            mf=max(mf,mpp[s[r]-'A']);
            if((r-l+1)-mf<=k)
            {
                maxl=max(maxl,r-l+1);

            }
            else
            {
                while((r-l+1)-mf>k)
                {
                    mpp[s[l]-'A']--;
                    l++;
                }
            }
            

        }
        return maxl;
    }
};