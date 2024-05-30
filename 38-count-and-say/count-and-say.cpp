class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string s = countAndSay(n - 1);
        string t = "";
        int cnt = 1;
        int i = 1;
        char num = s[0];

        while (i < s.size()) {
            if (s[i] == num) {
                cnt++;
            } else {
                t += to_string(cnt);
                t += num;
                num = s[i];
                cnt = 1;
            }
            i++;
        }
        // Append the last counted number
        t += to_string(cnt);
        t += num;

        return t;
    }
};