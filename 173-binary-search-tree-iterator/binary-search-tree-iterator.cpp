class BSTIterator {
private:
    stack<TreeNode*> st;
    
    void pushLeft(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushLeft(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};