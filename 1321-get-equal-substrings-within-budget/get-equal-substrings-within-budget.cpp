class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0;
        int j=0;
        int maxi=0;
        int n=s.size();
        int cst=0;
        while(j<n)
        {
            cst+=abs(s[j]-t[j]);
            while(i<n && cst>maxCost)
            {
            cst-=abs(s[i]-t[i]);
                
                i++;

            }
            maxi=max(j-i+1,maxi);
            j++;
        }
        return maxi;
    }
};