class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal; // XOR start and goal to find differing bits
        int cnt = 0;
        while (ans > 0) {
            cnt += ans & 1; // Check if the least significant bit is 1
            ans >>= 1; // Right shift to check the next bit
        }
        return cnt;
    }
};
