class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash;
        int maxi = 0;
        int l = 0;
        
        for (int r = 0; r < s.size(); ++r) {
            while (hash.find(s[r]) != hash.end()) {
                hash.erase(s[l]);
                ++l;
            }
            hash.insert(s[r]);
            maxi = max(r - l + 1, maxi);
        }
        
        return maxi;
    }
};