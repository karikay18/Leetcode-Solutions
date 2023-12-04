class Solution {
public:
    string largestGoodInteger(string num) {
        char res=-1;
        for(int i=2;i<num.size();i++)
        {
            if(num[i]==num[i-2] && num[i]==num[i-1])
            {
                res=max(num[i],res);
            }
        }
        if(res==-1)
        {
            return "";
        }
        else{
            return string(3,res);
        }
    }
};