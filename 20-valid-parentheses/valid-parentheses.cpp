class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                if(stk.empty()) // If stack is empty, there's no corresponding opening bracket
                    return false;
                char topChar = stk.top();
                stk.pop();
                if((c == ')' && topChar != '(') || 
                   (c == ']' && topChar != '[') || 
                   (c == '}' && topChar != '{')) {
                    return false; // Mismatched closing bracket
                }
            }
        }
        return stk.empty(); // If stack is empty, all brackets are matched
    }
};