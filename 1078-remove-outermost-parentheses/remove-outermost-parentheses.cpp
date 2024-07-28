class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        int open=1;
        int close=0;
        string res;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='(')
            {
                open++;
            }
            else if(s[i]==')')
            {
                close ++;
            }
            if(open==close)
            {
                close=0;
                open=0;
            }
            if(open>1)
            {
                res+=s[i];
            }

        }
        return res;
    }
};