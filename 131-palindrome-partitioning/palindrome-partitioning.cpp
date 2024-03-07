class Solution {
public:
   vector<vector<string>> partition(string s) {
       vector<vector<string>> res;
       vector<string>path;
       solve(0,res,path,s);
       return res; 
    }
    
    void solve(int index,vector<vector<string>> &res,vector<string> &path,string &s)
    {
        if(index==s.size())
        { 
            res.push_back(path);
            return ;
        }
        for(int i=index;i<s.size();i++)
        {
            if(ispalin(index,i,s))
            {
                path.push_back(s.substr(index,i-index+1));
                solve(i+1,res,path,s);
                path.pop_back();
            }
        }
    }
    
    bool ispalin(int start, int end, string &s) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

};