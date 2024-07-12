class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hasht, hashs;
        for (char c : t) {
            hasht[c]++;
        }
        int cnt = 0;
        int minl = INT_MAX;
        pair<int, int> make;
        int i = 0, j = 0;
        int required = hasht.size();

        while (j < s.size()) {
            if (hasht.find(s[j]) != hasht.end()) {
                hashs[s[j]]++;
                if (hashs[s[j]] == hasht[s[j]]) {
                    cnt++;
                }
            }

            while (cnt == required) {
                if (minl > j - i + 1) {
                    minl = j - i + 1;
                    make = {i, j};
                }
                if (hasht.find(s[i]) != hasht.end()) {
                    hashs[s[i]]--;
                    if (hashs[s[i]] < hasht[s[i]]) {
                        cnt--;
                    }
                }
                i++;
            }
            j++;
        }

        if (minl == INT_MAX) {
            return "";
        }

        return s.substr(make.first, minl);
    }
};