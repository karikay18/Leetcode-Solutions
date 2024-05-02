class Solution {
public:
    string reverseWords(string s) {
    stack<string> st;
    string temp;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {

            if (!temp.empty()) // Ignore consecutive spaces
                st.push(temp);
            temp.clear();
        } else {
            temp += s[i];
        }
    }
    if (!temp.empty()) // Push the last word if it's not empty
        st.push(temp);

    string res;
    while (!st.empty()) {
        res += st.top();
        st.pop();
        if (!st.empty()) {
            res += ' ';
        }
    }
    return res;
}
};