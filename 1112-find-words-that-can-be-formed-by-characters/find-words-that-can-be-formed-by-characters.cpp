#include <vector>
#include <string>

class Solution {
public:
    bool solve(string &word,vector<int> &hash) {
        vector<int> c(26, 0);
        for (char ch : word) {
            int x = ch - 'a';
            c[x]++;
            if (c[x] > hash[x]) {
                return false;
            }
        }
        return true;
    }

    int countCharacters(vector<string>& words,string &chars) {
        vector<int> hash(26, 0);
        int res = 0;
        for (char ch : chars) {
            int x = ch - 'a';
            hash[x]++;
        }
        for (string &word : words) {
            if (solve(word, hash)) {
                res += word.size();
            }
        }
        return res;
    }
};
