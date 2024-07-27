class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int res = 0;
        int i = n - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count the length of the last word
        while (i >= 0 && s[i] != ' ') {
            res++;
            i--;
        }

        return res;
    }
};
