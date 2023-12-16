class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) {
            return false; // Anagrams must have the same length
        }

        int hash1[26] = {0};
        int hash2[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            hash1[s[i] - 'a']++;
            hash2[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (hash1[i] != hash2[i]) {
                return false; // If counts don't match, not an anagram
            }
        }

        return true; // If all counts match, it's an anagram
    }
};