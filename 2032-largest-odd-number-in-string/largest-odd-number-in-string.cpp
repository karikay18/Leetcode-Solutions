#include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        string ans = "";
        for (int i = n - 1; i >= 0; --i) {
            if ((num[i] - '0') % 2 != 0) {
                ans = num.substr(0, i + 1); // Store the substring up to the largest odd digit
                break; // Found the largest odd digit, exit the loop
            }
        }
        return ans;
    }
};
