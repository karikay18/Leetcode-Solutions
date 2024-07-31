#include <unordered_set>

class Solution {
public:
    int helper(int n) {
        int ans = 0;
        while (n != 0) {
            int temp = n % 10;
            ans += temp * temp;
            n = n / 10;
        }
        return ans;
    }

    bool isHappy(int n) {
        std::unordered_set<int> hash;
        while (n != 1 && !hash.count(n)) {
            hash.insert(n);
            n = helper(n);
        }
        return n == 1;
    }
};
