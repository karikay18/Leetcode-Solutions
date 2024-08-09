class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();
            if (temp->right != NULL) {
                st.push(temp->right);  
            }
            if (temp->left != NULL) {
                st.push(temp->left);
            }
            if (!st.empty()) {
                temp->right = st.top();
            }
            temp->left = NULL;
        }
    }
};