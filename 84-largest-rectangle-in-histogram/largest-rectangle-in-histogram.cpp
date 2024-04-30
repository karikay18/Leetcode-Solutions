class Solution {
public:
    int largestRectangleArea(std::vector<int>& arr) {
        int n = arr.size();
        int ls[n];
        int rs[n];
        std::stack<int> st;
        
        // Compute ls array
        for(int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ls[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        
        // Clear the stack for re-use
        while (!st.empty()) st.pop();
        
        // Compute rs array
        for(int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            rs[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }
        
        int maxa = 0;
        for(int i = 0; i < n; i++) {
            maxa = std::max(maxa, arr[i] * (rs[i] - ls[i] + 1));
        }
        return maxa;
    }
};