class Solution {
public:
    int strStr(string haystack, string needle) {
        int ns=needle.size();
        int hs=haystack.size();
        int j=ns-1;
        for(int i=0;i<hs;i++)
        {
            if(haystack.substr(i,ns)==needle)return i;

        }
        return -1;
    }
};