class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = i + 1;
        int res = 0;
        int p = 0;
        while (j < prices.size()) {
            if (prices[j] > prices[i]) {
                res += prices[j] - prices[i];
            }
            i++;
            j++;
        }
        return res;
    }
};