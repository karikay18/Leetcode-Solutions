class Solution {
public:
    int myAtoi(string s) {
        int res=0;
        int i=0;
        int flag=1;
        while(s[i]==' ' )
        {
            // if()
            i++;
        }
        if (s[i] == '-') {
            flag = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        while(i<s.size() && isdigit(s[i]))
        {
             int digit = s[i] - '0';
            
            // Check for overflow
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return flag == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + digit;
            i++;
        }
        return flag*res;

    }
};